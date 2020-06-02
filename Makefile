# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/28 12:05:16 by tsarafia          #+#    #+#              #
#    Updated: 2020/05/28 12:07:45 by tsarafia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Cub3D

SRCS =	cub3d.c 						\
		srcs/bitmap.c 					\
		srcs/form_parse.c				\
		srcs/keypress.c 				\
		srcs/parse_info.c 			\
		srcs/parse.c 						\
		srcs/parse2.c						\
		srcs/parsing_map1.c 		\
		srcs/parsing_map2.c 		\
		srcs/parsing_res.c 			\
		srcs/parsing_rgb.c 			\
		srcs/parsing_texture.c 	\
		srcs/raycasting.c 			\
		srcs/raycasting2.c 			\
		srcs/raycasting3.c 			\
		srcs/sprite.c						\
		srcs/sprite2.c					\
		srcs/utils.c 						\
		srcs/utils2.c 						\
		libft/ft_atoi.c					\
		libft/ft_bzero.c				\
		libft/ft_isalnum.c			\
		libft/ft_isalpha.c			\
		libft/ft_isascii.c			\
		libft/ft_isdigit.c			\
		libft/ft_strdup.c				\
		libft/ft_strlen.c				\
		gnl/get_next_line.c			\
		gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEAD = headers/cub.h

AR = ar rc

LIB = ranlib

FLAGS = -Wall -Wextra -Werror
LIBX = -L ./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd 

all		: $(NAME)

$(NAME)	:	$(OBJS)
			clang $(FLAGS) -o $(NAME) $(OBJS) $(LIBX)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)
			rm -f *.bmp

re		:	fclean all

.PHONY	:	all clean fclean re
