NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror


MYLIB = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GET_NEXT = get_next_line_curses/get_next_line.c get_next_line_curses/get_next_line_utils.c

MLX = -L/usr/include/minilibx-linux -lmlx -lXext -lX11
MLX_INC = -I/usr/include/minilibx-linux

RM = rm -rf

SRCS = so_long.c check_map.c erro_funct.c flood_fill.c \
	flood_fill_collect.c map_render.c mlx_tools.c parcing.c $(GET_NEXT)


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MYLIB) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MYLIB) $(PRINTF) $(MLX) -o $(NAME)


$(MYLIB):
	make -C libft

$(PRINTF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@


clean:
	$(RM) $(OBJS)
	@make -C libft clean
	@make -C ft_printf clean

fclean: clean	
	$(RM) $(NAME)
	@make -C libft fclean
	@make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re











