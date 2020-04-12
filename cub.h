/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <tsarafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:59:08 by tsarafia          #+#    #+#             */
/*   Updated: 2020/03/11 14:57:45 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# define BUFFER_SIZE 2048

struct		s_parse
{
	char *res_x;
	char *res_y;
	char *north;
	char *south;
	char *west;
	char *east;
	char *sprite;
	char *floor;
	int floor_rgb[3];
	char *ceiling;
	int ceiling_rgb[3];
	char **map;
	int i;
	int strlen;
	int nbline;
	int pos[2];
	char side;

};
typedef	struct	s_parse	t_parse;


struct		s_cub
{
	t_parse parse;
};
typedef struct	s_cub t_cub;

//parsing_res.c
void	parsing_res_x(t_cub *cub, char *line);
void	parsing_res_y(t_cub *cub, char *line);
int		parsing_res(t_cub *cub, char *line);
//parsing_rgb.c
int		parsing_floor(t_cub *cub, char *line);
int		parsing_ceiling(t_cub *cub, char *line);
//parsing_texture.c
int		parsing_north(t_cub *cub, char *line);
int		parsing_west(t_cub *cub, char *line);
int		parsing_east(t_cub *cub, char *line);
int		parsing_south(t_cub *cub, char *line);
//parse.c
void	ft_start(t_cub *cub);
void	ft_error(char *str);
int		parsing_line(t_cub *cub, char *str);
int		parsing(t_cub *cub, char *line);
//parsing_map1.c
void	fill_sp(t_cub *cub);
int		find_in(char c, char *str);
void	show_map(t_cub *cub);
int		parsing_map(t_cub *cub, char *line);
int 	check_map(t_cub *cub);
//parsing_map2.c
int		check_around(t_cub *cub, int j, int i, char *s);
void	line_check(t_cub *cub, int j);
void	first_line_check(t_cub *cub);
void	last_line_check(t_cub *cub);




#endif
