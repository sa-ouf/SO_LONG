/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:42:51 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/26 16:30:00 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**allocat(int count, int fd)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	map = malloc((count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (map[i] = NULL, map);
}

void	check_rectangular(char **map)
{
	int	i;
	int	width;

	if (!map || !map[0])
		error_check(map, 3);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			error_check(map, 1);
		i++;
	}
}

void	check_wall(char **map)
{
	int	i;
	int	j;
	int	wid;
	int	height;

	i = 0;
	j = 0;
	wid = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	while (j < wid)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			error_check(map, 0);
		j++;
	}
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][wid - 1] != '1')
			error_check(map, 0);
		i++;
	}
}

void	check_char(t_data *info, char **map)
{
	int	e;
	int	collec;

	int (i), j, player;
	player = 0;
	e = 0;
	collec = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				collec++;
		}
	}
	info->tot_collectibles = collec;
	if (player != 1 || e != 1 || collec < 1)
		exit((ft_printf("Error\nInvalid number of chars\n"), free_map(map), 1));
}
