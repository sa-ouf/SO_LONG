# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 18:43:58 by snait-ai          #+#    #+#              #
#    Updated: 2024/12/21 18:11:17 by snait-ai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = print_char.c print_str.c \
	print_nbr.c print_hexdec.c \
	print_unbre.c ft_printf.c print_address.c

CC = cc 
FLAGS = -Wall -Wextra -Werror
RM = rm -fr
AR = ar -rcs

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) -c $(FLAGS) $^

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : fclean clean all re 
