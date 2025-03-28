/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:37:26 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/26 14:08:33 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_postion	find_player(char **map, int row)
{
	int			i;
	int			col;
	int			j;
	t_postion	player;

	col = ft_strlen(map[0]);
	i = 0;
	player.x = -1;
	player.y = -1;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == 'P')
			{
				player.x = i;
				player.y = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

static char	**cpy_map_flood(char **map, int row)
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

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	disply_erro(char **cpy_map, char **map)
{
	free_map(cpy_map);
	free_map(map);
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	check_valid_map(char **map, int r_x, int c_y, int row)
{
	char	**cpy_map;
	int		col;
	int		i;
	int		j;

	col = ft_strlen(map[0]);
	cpy_map = cpy_map_flood(map, row);
	if (!cpy_map)
	{
		free_map(map);
		return ;
	}
	flood_fill(cpy_map, c_y, r_x);
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (cpy_map[i][j] == 'E' || cpy_map[i][j] == 'C')
				disply_erro(cpy_map, map);
		}
	}
	free_map(cpy_map);
}
