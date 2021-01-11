# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 12:54:38 by user42            #+#    #+#              #
#    Updated: 2021/01/11 09:00:28 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS =	cub3d.c 						\
		srcs/bitmap.c 					\
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
		srcs/free.c						\
		srcs/mlx.c						\
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
HEAD=		-I headers -I minilibx-linux
CC=			clang
CFLAGS=		-Wall -Werror -Wextra
MLX_DIR=	minilibx-linux
LDFLAGS=	-L ${MLX_DIR}
LIBS=		-lm -lmlx -lXext -lX11

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
$(NAME):	${OBJS}
		make -C ${MLX_DIR}
		${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME} ${LIBS}

all:	${NAME}

clean:
		rm -rf ${OBJS}
fclean:	clean
		rm -rf ${NAME} screen.bmp
re:	fclean all
.PHONY:	all clean fclean re


