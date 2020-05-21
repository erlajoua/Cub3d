NAME = Cub3D

SRCS = srcs

SRCS =	srcs/bitmap.c 			\
		srcs/keypress.c 		\
		srcs/parse_info.c 		\
		srcs/parse.c 			\
		srcs/parsing_map1.c 	\
		srcs/parsing_map2.c 	\
		srcs/parsing_res.c 		\
		srcs/parsing_rgb.c 		\
		srcs/parsing_texture.c 	\
		srcs/raycasting.c 		\
		srcs/raycasting2.c 		\
		srcs/raycasting3.c 		\
		srcs/sprite.c			\
		srcs/sprite2.c

OBJS = $(SRCS:.c=.o)

HEAD = cub.h

AR = ar rc

LIB = ranlib

FLAGS = -Wall -Wextra -Werror

all		: $(NAME)

.c.o	:
			gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(LIB) $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re