/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:11:23 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/25 14:15:57 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_exit(t_data *info, char *message, int c)
{
	ft_putstr_fd(message, 2);
	if (info->map)
		free_map(info->map);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->wall)
		mlx_destroy_image(info->mlx, info->wall);
	if (info->player)
		mlx_destroy_image(info->mlx, info->player);
	if (info->floor)
		mlx_destroy_image(info->mlx, info->floor);
	if (info->collect)
		mlx_destroy_image(info->mlx, info->collect);
	if (info->exit)
		mlx_destroy_image(info->mlx, info->exit);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
	exit(c);
}

void	check_ber(char *name)
{
	if (name[ft_strlen(name) - 5] == '/'
		|| ft_strncmp(&name[ft_strlen(name) - 4], ".ber", 4)
		|| ft_strlen(name) <= 4)
	{
		ft_printf("Error\nmap filename extention is wrong\n");
		exit(1);
	}
}

void	init_game(t_data *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_free_exit(info, "Error\nmlx connection faild\n", 1);
	info->win = mlx_new_window(info->mlx, info->columns * 64, info->rows * 64,
			"my_window");
	if (!info->win)
		ft_free_exit(info, "Error\nopening window failed\n", 1);
}

void	init_struc(t_data *info)
{
	info->wall = NULL;
	info->player = NULL;
	info->floor = NULL;
	info->exit = NULL;
	info->collect = NULL;
	info->wid_img = 0;
	info->hei_img = 0;
	info->movement = 0;
	info->tot_collectibles = 0;
	info->mlx = NULL;
	info->win = NULL;
}

int	main(int ac, char *av[])
{
	t_data	info;

	if (ac == 2)
	{
		check_ber(av[1]);
		init_struc(&info);
		parcing(&info, av[1]);
		init_game(&info);
		store_image_of_game(&info);
		render_map_for_game(&info);
		mlx_hook(info.win, 2, 1, handling_key_press, &info);
		mlx_hook(info.win, 17, 0, close_my_game, &info);
		mlx_loop(info.mlx);
	}
	else
		ft_putstr_fd("Error\nInvalid number of args\n", 2);
	return (0);
}
