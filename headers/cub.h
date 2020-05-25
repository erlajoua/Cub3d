/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <tsarafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:59:08 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 11:21:36 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

// #include "../libft/libft.h"
// #include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
//#define BUFFER 2048
// # define WIN_W 400
// # define WIN_H 400
# define D_PI 3.14159265358979323846

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
	int color;
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
	int *datatest;
	int res;
	int txt;
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
	int save;
};
typedef struct s_parse t_parse;

struct s_cub
{
	t_parse parse;
	int start_y;
	int ind_y;
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
	int		width;
	int		height;
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

/*void	ft_error(char *str);
void	draw_sprite(t_info *infos, t_cub *cub, t_mlx *mlx);
void	bitmap(t_mlx *mlx);
void	chose_color(t_info *infos);
void first_line_check(t_cub *cub);
void last_line_check(t_cub *cub);
void line_check(t_cub *cub, int j);
void	setdrawp(t_info *infos, t_cub *cub);
int check_around(t_cub *cub, int j, int i, char *s);
void	all(t_info *infos, t_mlx *mlx, t_cub *cub);*/

//bitmap
void	bitmap(t_mlx *mlx);
void	header_bmp(t_mlx *mlx, int fd);
void	vertical(int fd, t_mlx *mlx);

//keypressed 
int		keypressed(int key, void *p);
void	cam_lr(t_info *infos, int key);
void	mv_lr(t_info *infos, t_cub *cub, int key);
void	updown(t_info *infos, t_cub *cub, int key);

//parse_info.c
int parsing_informations(t_cub *cub, t_info *infos, char *line);
void show_parsed(t_cub *cub);
int parsing_line(t_cub *cub, char *str);

//parse.c
void ft_start(t_cub *cub);
void	init_window(t_mlx *mlx, t_info *infos);
void	get_lines(t_cub *cub, t_info *infos, char *av1);
void	want_save(t_cub *cub, int ac, char *av2);

//parsing_res.c
void	parsing_res_x(t_cub *cub, char *line);
void	parsing_res_y(t_cub *cub, char *line);
int	parsing_res(t_cub *cub, t_info *infos, char *line);

//raycasting.c
void	setdrawp(t_info *infos, t_cub *cub);
void	sidedistxy(t_info *infos);
void	dda(t_info *infos, t_cub *cub);
void	all(t_info *infos, t_mlx *mlx, t_cub *cub);
int		raycasting(t_mlx *mlx, t_info *infos, t_cub *cub);

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

//parsing_res.c
void parsing_res_x(t_cub *cub, char *line);
void parsing_res_y(t_cub *cub, char *line);
int parsing_res(t_cub *cub, t_info *infos, char *line);


//parsing_rgb.c
int parsing_floor(t_cub *cub, char *line);
int parsing_ceiling(t_cub *cub, char *line);

//parsing_texture.c
int parsing_north(t_cub *cub, char *line);
int parsing_west(t_cub *cub, char *line);
int parsing_east(t_cub *cub, char *line);
int parsing_south(t_cub *cub, char *line);
int	parsing_sprite(t_cub *cub, char *line);

//raycasting
int	raycasting(t_mlx *mlx, t_info *infos, t_cub *cub);
void	all(t_info *infos, t_mlx *mlx, t_cub *cub);
void	dda(t_info *infos, t_cub *cub);
void	sidedistxy(t_info *infos);
void	setdrawp(t_info *infos, t_cub *cub);

//raycasting2
void	chose_color(t_info *infos);
void	initvalue(t_info *infos, t_cub *cub);
void	draw(t_mlx *mlx, t_info *infos, t_cub *cub);
void	drawwall(t_mlx *mlx, t_info *infos);
void	drawsky(t_mlx *mlx, t_info *infos, t_cub *cub);

//raycasting3
void	raydirxy(t_info *infos);

//sprite.c
void    start_spr(t_info *infos);
void    init_spr(t_info *infos, t_cub *cub);
void    get_nb_spr(t_info *infos, t_cub *cub);
void    disp_spr(t_info *infos, t_mlx *mlx);
void    calc_spr(t_info *infos, t_mlx *mlx);
void    draw_sprite(t_info *infos, t_cub *cub, t_mlx *mlx);

// void	ft_error(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(char *str);

void	init_nw(t_info *infos, t_cub *cub);
void	init_se(t_info *infos, t_cub *cub);

//libft
int	ft_strlen(char *str);
char	*ft_strdup(const char *s1);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);


//get_next_line
int			get_next_line(int fd, char **line);

#endif
