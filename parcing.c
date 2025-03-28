/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:16:26 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/25 15:41:57 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	count_line(int fd)
{
	int		c;
	char	*line;

	c = 0;
	line = get_next_line(fd);
	while (line)
	{
		c++;
		free(line);
		line = get_next_line(fd);
	}
	return (c);
}

static void	check_other_chars(char **map, int row)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	col = ft_strlen(map[0]);
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] != 'P' && map[i][j] != '1' && map[i][j] != 'E'
				&& map[i][j] != 'C' && map[i][j] != '0')
				error_check(map, 2);
			j++;
		}
		i++;
	}
}

static void	check_retur_find_player(t_data *info, int x, int y)
{
	if (x == -1 || y == -1)
		ft_free_exit(info, "Error\n player is not found in map\n", 1);
}

static void	function_map(t_data *info, int x, int y, int count)
{
	check_other_chars(info->map, info->rows);
	check_valid_map(info->map, x, y, count);
	check_valid_map_for_c(info->map, x, y, count);
}

void	parcing(t_data *info, char *name)
{
	int			fd;
	int			count;
	t_postion	pos;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit((ft_printf("Error\nOpen file is failed\n"), 1));
	count = count_line(fd);
	close(fd);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit((ft_printf("Error\nOpen file is failed\n"), 1));
	info->map = allocat(count, fd);
	close(fd);
	if (!info->map || info->map[0] == NULL)
		ft_free_exit(info, "Error\nmy map is empty or invalid\n", 1);
	info->rows = count;
	info->columns = (int)ft_strlen(info->map[0]);
	check_rectangular(info->map);
	check_wall(info->map);
	check_char(info, info->map);
	pos = find_player(info->map, count);
	check_retur_find_player(info, pos.x, pos.y);
	function_map(info, pos.x, pos.y, count);
}
