# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snait-ai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 09:20:32 by snait-ai          #+#    #+#              #
#    Updated: 2024/11/16 18:39:59 by snait-ai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC = ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c\
	ft_bzero.c ft_itoa.c ft_memset.c ft_strdup.c ft_strncmp.c ft_calloc.c \
	ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_isalnum.c \
	ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_isalpha.c  \
	ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isascii.c ft_memcmp.c \
	ft_putstr_fd.c ft_strlcpy.c ft_substr.c ft_isdigit.c ft_memcpy.c ft_split.c \
	ft_strlen.c ft_tolower.c 

SRC_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
	    ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstlast_bonus.c
 
OBJS = $(SRC:.c=.o)
B_OBJS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

bonus: $(OBJS) $(B_OBJS)
	$(AR) $(NAME) $(B_OBJS)
	@touch bonus

%.o: %.c
	$(CC) -c $(FLAGS) $?

clean:
	$(RM) $(OBJS) $(B_OBJS) bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all  clean fclean re
