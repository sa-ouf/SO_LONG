/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:03:01 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/26 14:07:27 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	**cpy_map_flood_c(char **map, int row)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = malloc((row + 1) * sizeof(char *));
	if (!cpy)
		return (free_map(map), NULL);
	while (i < row)
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
		{
			while (--i >= 0)
				free(cpy[i]);
			free(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

static void	flood_fill_c(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_c(map, x + 1, y);
	flood_fill_c(map, x - 1, y);
	flood_fill_c(map, x, y + 1);
	flood_fill_c(map, x, y - 1);
}

static void	disply_erro(char **cpy_map, char **map)
{
	free_map(cpy_map);
	free_map(map);
	ft_printf("Error\nInvalid map the collect is surounded by wall and exit\n");
	exit(0);
}

void	check_valid_map_for_c(char **map, int x, int y, int row)
{
	char	**cpy_map;
	int		col;
	int		i;
	int		j;

	col = ft_strlen(map[0]);
	cpy_map = cpy_map_flood_c(map, row);
	if (!cpy_map)
	{
		free_map(map);
		return ;
	}
	flood_fill_c(cpy_map, y, x);
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (cpy_map[i][j] == 'C')
				disply_erro(cpy_map, map);
		}
	}
	free_map(cpy_map);
}
