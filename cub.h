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
};
typedef	struct	s_parse	t_parse;


struct		s_cub
{
	t_parse parse;
};
typedef struct	s_cub t_cub;


void	ft_error(char *str);
int		num_count(int n);
int		parsing(t_cub *cub, char *line);
int		parsing_ceiling(t_cub *cub, char *line);
int		parsing_floor(t_cub *cub, char *line);
int		parsing_map(t_cub *cub, char *line);
int		parsing_line(t_cub *cub, char *str);

#endif
