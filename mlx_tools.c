/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:47:48 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/25 14:49:45 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_image_of_game(t_data *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->wid_img, &game->hei_img);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->wid_img, &game->hei_img);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->wid_img, &game->hei_img);
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&game->wid_img, &game->hei_img);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->wid_img, &game->hei_img);
	if (!game->wall || !game->player || !game->exit || !game->collect
		|| !game->floor)
		ft_free_exit(game, "Error\nfailed loading images\n", 1);
}

void	destroy_all_images(t_data *image)
{
	if (image->player)
		mlx_destroy_image(image->mlx, image->player);
	if (image->collect)
		mlx_destroy_image(image->mlx, image->collect);
	if (image->floor)
		mlx_destroy_image(image->mlx, image->floor);
	if (image->exit)
		mlx_destroy_image(image->mlx, image->exit);
	if (image->wall)
		mlx_destroy_image(image->mlx, image->wall);
}

void	free_all(t_data *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	destroy_all_images(info);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	free_map(info->map);
}

int	close_my_game(t_data *info)
{
	free_all(info);
	ft_printf("my game is closed\n");
	exit(0);
	return (0);
}
