/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:50:16 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/25 15:01:11 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_data *img, int i, int j)
{
	if (img->map[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->wall, j * img->wid_img,
			i * img->hei_img);
	else if (img->map[i][j] == '0')
		mlx_put_image_to_window(img->mlx, img->win, img->floor, j
			* img->wid_img, i * img->hei_img);
	else if (img->map[i][j] == 'P')
		mlx_put_image_to_window(img->mlx, img->win, img->player, j
			* img->wid_img, i * img->hei_img);
	else if (img->map[i][j] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->exit, j * img->wid_img,
			i * img->hei_img);
	else if (img->map[i][j] == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->collect, j
			* img->wid_img, i * img->hei_img);
}

void	render_map_for_game(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			ft_put_img(info, i, j);
			j++;
		}
		i++;
	}
}

void	check_if_exit(t_data *game, int n_row, int n_col)
{
	if (game->tot_collectibles == 0)
	{
		game->map[game->pos.x][game->pos.y] = '0';
		game->map[n_row][n_col] = 'P';
		game->movement++;
		ft_printf("Move Count: %d\n", game->movement);
		ft_free_exit(game, "You Win\n", 0);
	}
	else
		return ;
}

void	move_my_player(t_data *game, int d_y, int d_x)
{
	int			n_col;
	int			n_row;
	t_postion	post;

	post = find_player(game->map, game->rows);
	n_row = post.x + d_x;
	n_col = post.y + d_y;
	if (game->map[n_row][n_col] == '1' || (game->map[n_row][n_col] == 'E'
			&& game->tot_collectibles > 0))
		return ;
	if (game->map[n_row][n_col] == 'C')
	{
		game->map[n_row][n_col] = '0';
		game->tot_collectibles--;
	}
	if (game->map[n_row][n_col] == 'E')
		check_if_exit(game, n_row, n_col);
	game->map[post.x][post.y] = '0';
	game->map[n_row][n_col] = 'P';
	game->pos.x = n_row;
	game->pos.y = n_col;
	game->movement++;
	ft_printf("Move Count: %d\n", game->movement);
	render_map_for_game(game);
}

int	handling_key_press(int k_number, t_data *info)
{
	if (k_number == 65307)
		ft_free_exit(info, "my game is closed\n", 0);
	if (k_number == 65362)
		move_my_player(info, 0, -1);
	if (k_number == 65364)
		move_my_player(info, 0, 1);
	if (k_number == 65361)
		move_my_player(info, -1, 0);
	if (k_number == 65363)
		move_my_player(info, 1, 0);
	return (0);
}
