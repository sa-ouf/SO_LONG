/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:28:42 by snait-ai          #+#    #+#             */
/*   Updated: 2025/03/26 16:23:37 by snait-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line_curses/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pos
{
	int			x;
	int			y;
}				t_postion;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			columns;
	int			rows;
	void		*wall;
	void		*player;
	void		*floor;
	void		*exit;
	void		*collect;
	int			wid_img;
	int			hei_img;
	t_postion	pos;
	int			collected;
	int			tot_collectibles;
	int			movement;
}				t_data;

t_postion		find_player(char **map, int row);

void			check_valid_map(char **map, int x, int y, int row);
void			check_valid_map_for_c(char **map, int x, int y, int row);
void			free_map(char **map);
void			parcing(t_data *info, char *name);
void			render_map_for_game(t_data *info);
int				handling_key_press(int k_number, t_data *info);
int				close_my_game(t_data *info);
void			ft_free_exit(t_data *info, char *message, int c);
void			store_image_of_game(t_data *game);
void			destroy_all_images(t_data *image);
void			free_all(t_data *info);
void			error_check(char **map, int x);
void			check_char(t_data *info, char **map);
void			check_wall(char **map);
char			**allocat(int count, int fd);
void			check_rectangular(char **map);

#endif
