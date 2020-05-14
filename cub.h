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
#define CUB_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#define BUFFER_SIZE 2048
#define D_PI 3.14159265358979323846


struct s_sprite
{
	double first;
	double second;
	double x;
	double y;
	void *txt; 
};
typedef struct s_sprite t_sprite;

struct s_txtr
{
	void *img;
	char *data;
	int width;
	int height;
};
typedef struct s_txtr t_txtr;

struct s_info
{
	t_txtr txtr[6];
	t_sprite *sprite;
	int spr_nb;
	int *spr_order;
	double *spr_dist;	
	double *zbuffer;
	double spr_x;
	double spr_y;
	double invdet;
	double transx;
	double transy;
	int sprscreen_x;
	int sprscreen_y;
	int spr_h;
	int drawstart_x;
	int drawstart_y;
	int drawend_x;
	int drawend_y;
	int spr_w;

	double posx;
	double posy;
	double mvspeed;
	double dirx;
	double diry;
	double planex;
	double planey;
	double camerax;
	double raydirx;
	double raydiry;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	int stepx;
	int stepy;
	int side;
	int hit;
	int mapx;
	int mapy;
	int lineHeight;
	int drawstart;
	int drawend;
	int x;
	double olddirx;
	double oldplanex;
	double savedir;
	int *dataimg;
	void *tximg;
	int color; //color tmp pour les murs, sol, plafond
	int texnum;
	double wallx;
	int tex_x;
	int tex_y;
	int txwidth;
	int txheight;
	double step;
	double texpos;
	int hex;
	int infotxtr;
	int RESX;
	int RESY;
};
typedef struct s_info t_info;

struct s_parse
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
	int flag;
};
typedef struct s_parse t_parse;

struct s_cub
{
	t_parse parse;
};
typedef struct s_cub t_cub;

struct s_img
{
	void	*img_ptr;
	int 	bpp;
	int 	size_l;
	int		*data;
	int		*data2;
	int		endian;
};
typedef struct s_img t_img;

struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*xpm_ptr;
	t_img	img;
};
typedef struct s_mlx t_mlx;

//parse_info.c
int parsing_informations(t_cub *cub, char *line);
void show_parsed(t_cub *cub);
int parsing_line(t_cub *cub, char *str);
//parsing_res.c
void parsing_res_x(t_cub *cub, char *line);
void parsing_res_y(t_cub *cub, char *line);
int parsing_res(t_cub *cub, char *line);
//parsing_rgb.c
int parsing_floor(t_cub *cub, char *line);
int parsing_ceiling(t_cub *cub, char *line);
//parsing_texture.c
int parsing_north(t_cub *cub, char *line);
int parsing_west(t_cub *cub, char *line);
int parsing_east(t_cub *cub, char *line);
int parsing_south(t_cub *cub, char *line);
//parse.c
void ft_start(t_cub *cub);
void ft_error(char *str);
//parsing_map1.c
void fill_sp(t_cub *cub);
int find_in(char c, char *str);
void show_map(t_cub *cub);
void parsing_map(t_cub *cub, char *line);
int check_map(t_cub *cub);
//parsing_map2.c
int check_around(t_cub *cub, int j, int i, char *s);
void line_check(t_cub *cub, int j);
void first_line_check(t_cub *cub);
void last_line_check(t_cub *cub);


void    draw_sprite(t_info *infos, t_cub *cub, t_mlx *mlx);
void		sort_spr(t_info *infos, t_cub *cub);
void    start_spr(t_info *infos, t_cub *cub);

#endif
