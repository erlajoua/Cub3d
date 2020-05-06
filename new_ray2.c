#define mapWidth 24
#define mapHeight 24

#include "cub.h"

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

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
	t_txtr txtr[4];
	double posx;
	double posy;
	double mvspeed;
	double dirx;
	double diry;
	double planeX;
	double planeY;
	double cameraX;
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
};
typedef struct s_info t_info;

void	chose_color(t_info *infos) 
{
	if (infos->side == 0) //EW
	{
		if (infos->raydirx > 0)
			infos->color = (int)0xFFFF00; //jaune
		else
			infos->color = (int)0x00FF00; //vert
	}
	else if (infos->side == 1) //NS
	{
		if (infos->raydiry < 0)
			infos->color = (int)0xFFFFFF; //gris
		else
			infos->color = (int)0xFF0000; //rouge
	}
}

void	drawsky(t_mlx *mlx, t_info *infos)
{
	int j = 0;
	while (j < infos->drawstart)
	{
		mlx->img.data[infos->x + j * WIN_W] = (int)0x050E85;
		//mlx->img.data[infos->x + j * WIN_W] = (int)0x00FF00;
		j++;
	}
}

void	setdrawp(t_mlx *mlx, t_info *infos)
{
	infos->drawstart = -infos->lineHeight / 2 + WIN_H / 2;
	if (infos->drawstart < 0)
		infos->drawstart = 0;
	infos->drawend = infos->lineHeight / 2 + WIN_H / 2;
	if (infos->drawend >= WIN_H)
		infos->drawend = WIN_H - 1;
	infos->texnum = worldMap[infos->mapx][infos->mapy] - 1;
	if (infos->side == 0)
		infos->wallx = infos->posy + infos->perpwalldist * infos->raydiry;
	else
		infos->wallx = infos->posx + infos->perpwalldist * infos->raydirx;
	infos->wallx -= floor(infos->wallx);
	infos->tex_x = (int)(infos->wallx * (double)infos->txtr[0].width);
	if (infos->side == 0 && infos->raydirx > 0)
		infos->tex_x = infos->txtr[0].width - infos->tex_x - 1;
	if (infos->side == 1 && infos->raydiry < 0)
		infos->tex_x = infos->txtr[0].width - infos->tex_x - 1;
	infos->step = 1.0 * infos->txtr[0].height / infos->lineHeight;
	infos->texpos = (infos->drawstart - WIN_H / 2 + infos->lineHeight / 2) * infos->step;
}

void	drawwall(t_mlx *mlx, t_info *infos)
{
	while (infos->drawstart < infos->drawend)
	{
		infos->tex_y = (int)infos->texpos & (infos->txtr[0].height - 1);
		infos->texpos += infos->step;
		infos->dataimg = (int *)mlx_get_data_addr(infos->txtr[0].img, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);

		infos->hex = infos->dataimg[infos->tex_y * infos->txtr[0].width + infos->tex_x];

		mlx->img.data[infos->x + (infos->drawend * WIN_W)] = infos->hex;
		infos->drawend--;
	}
}

void	draw(t_mlx *mlx, t_info *infos)
{
	// int infos->color;
	int k;

	chose_color(infos);
	setdrawp(mlx, infos);
	drawsky(mlx, infos);
	k = infos->drawend;
	drawwall(mlx, infos);

	//drawfloor
	while (k < WIN_H)
	{
		mlx->img.data[infos->x + k * WIN_W] = (int)0x2B1B14;
		k++;
	}
}

void raydirxy(t_info *infos)
{
	infos->mapx = (int)infos->posx;
	infos->mapy = (int)infos->posy;
	infos->cameraX = 2 * infos->x / (double)WIN_W - 1;
	infos->raydirx = infos->dirx + infos->planeX * infos->cameraX;
	infos->raydiry = infos->diry + infos->planeY * infos->cameraX;
	infos->deltadistx = (infos->raydiry == 0) ? 0 : ((infos->raydirx == 0) ? 1 : fabs(1 / infos->raydirx));
	infos->deltadisty = (infos->raydirx == 0) ? 0 : ((infos->raydiry == 0) ? 1 : fabs(1 / infos->raydiry));
}

void sidedistxy(t_info *infos)
{
	infos->hit = 0;
	if (infos->raydirx < 0)
	{
		infos->stepx = -1;
		infos->sidedistx = (infos->posx - infos->mapx) * infos->deltadistx;
	}
	else
	{
		infos->stepx = 1;
		infos->sidedistx = (infos->mapx + 1.0 - infos->posx) * infos->deltadistx;
	}
	if (infos->raydiry < 0)
	{
		infos->stepy = -1;
		infos->sidedisty = (infos->posy - infos->mapy) * infos->deltadisty;
	}
	else
	{
		infos->stepy = 1;
		infos->sidedisty = (infos->mapy + 1.0 - infos->posy) * infos->deltadisty;
	}
}

void dda(t_info *infos)
{
	while (infos->hit == 0)
	{
		if (infos->sidedistx < infos->sidedisty)
		{
			infos->sidedistx += infos->deltadistx;
			infos->mapx += infos->stepx;
			infos->side = 0;
		}
		else
		{
			infos->sidedisty += infos->deltadisty;
			infos->mapy += infos->stepy;
			infos->side = 1;
		}
		if (worldMap[infos->mapx][infos->mapy] > 0)
			infos->hit = 1;
	}
	if (infos->side == 0)
		infos->perpwalldist = (infos->mapx - infos->posx + (1 - infos->stepx) / 2) / infos->raydirx;
	else
		infos->perpwalldist = (infos->mapy - infos->posy + (1 - infos->stepy) / 2) / infos->raydiry;
	infos->lineHeight = (int)(WIN_H / infos->perpwalldist);
}

void all(t_info *infos, t_mlx *mlx)
{
	infos->x = 0;
	while (infos->x < WIN_W)
	{
		raydirxy(infos);
		sidedistxy(infos);
		dda(infos);
		draw(mlx, infos);
		infos->x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

void initializeValues(t_mlx *mlx, t_info *infos)
{
	infos->posx = 4, infos->posy = 3;
	infos->dirx = 0, infos->diry = 1;
	infos->planeX = 0.66, infos->planeY = 0;
	if (infos->diry == 0)
	{
		if (infos->dirx < 0)
			infos->savedir = 1;
		else if (infos->dirx > 0)
			infos->savedir = -1;
	}
	else if (infos->dirx == 0)
	{
		if (infos->diry < 0)
			infos->savedir = -1;
		else if (infos->diry > 0)
			infos->savedir = 1;
	}
	infos->mvspeed = 0.1;
}

void	updown(t_mlx *mlx, t_info *infos, int key)
{
		infos->mvspeed *= (key == 115) ? -1 : 1;
		if (worldMap[(int)(infos->posx + infos->dirx * infos->mvspeed)][(int)(infos->posy)] == 0)
			infos->posx += infos->dirx * infos->mvspeed;
		if (worldMap[(int)(infos->posx)][(int)(infos->posy + infos->diry * infos->mvspeed)] == 0)
			infos->posy += infos->diry * infos->mvspeed;
}

void	mv_lr(t_mlx *mlx, t_info *infos, int key)
{
		infos->mvspeed *= -infos->savedir;
		infos->mvspeed *= (key == 100) ? -1 : 1;
		if (worldMap[(int)(infos->posx)][(int)(infos->posy - infos->dirx * infos->mvspeed)] == 0)
			infos->posy -= infos->dirx * infos->mvspeed;
		if (worldMap[(int)(infos->posx + infos->mvspeed * infos->diry)][(int)(infos->posy)] == 0)
			infos->posx += infos->diry * infos->mvspeed;
}

void	cam_lr(t_mlx *mlx, t_info *infos, int key)
{
		double olddirx;
		double oldplanex;
		double angle;
		angle = D_PI / 30 * infos->savedir;
		angle *= (key == 65363) ? -1 : 1;

		olddirx = infos->dirx;
		oldplanex = infos->planeX;
		infos->dirx = infos->dirx * cos(angle) - infos->diry * sin(angle);
		infos->diry = olddirx * sin(angle) + infos->diry * cos(angle);
		infos->planeX = infos->planeX * cos(angle) - infos->planeY * sin(angle);
		infos->planeY = oldplanex * sin(angle) + infos->planeY * cos(angle);
}

int keypressed(int key, void *p)
{
	void **recup;
	t_info *infos;
	t_mlx *mlx;
	
	recup = (void **)p;
	infos = recup[0];
	mlx = recup[1];
	if (key == 65307)
		exit(0);
	infos->mvspeed = 0.3;
	if (key == 122 || key == 115) //up & down
	{
		updown(mlx, infos, key);	
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]));
	}
	else if (key == 113 || key == 100) //left & right
	{
		mv_lr(mlx, infos, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]));
	}
	else if (key == 65361 || key == 65363) //camera left & right
	{
		cam_lr(mlx, infos, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]));
	}
	return (1);
}

int main(void)
{
	t_info infos;
	t_mlx mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "Cub3d");
	infos.txtr[0].img = mlx_xpm_file_to_image(mlx.mlx_ptr, "east.xpm", &infos.txtr[0].width, &infos.txtr[0].height); //north.xpm
	infos.txtr[1].img = mlx_xpm_file_to_image(mlx.mlx_ptr, "south.xpm", &infos.txtr[1].width, &infos.txtr[1].height); //south.xpm
	infos.txtr[2].img = mlx_xpm_file_to_image(mlx.mlx_ptr, "weast.xpm", &infos.txtr[2].width, &infos.txtr[2].height); //weast.xpm
	infos.txtr[3].img = mlx_xpm_file_to_image(mlx.mlx_ptr, "east.xpm", &infos.txtr[3].width, &infos.txtr[3].height); //east.xpm

	//infos.tximg = mlx_xpm_file_to_image(mlx.mlx_ptr, "bricks.xpm", &infos.txwidth, &infos.txheight);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_W, WIN_H);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	initializeValues(&mlx, &infos);

	void *params[2];
	double time = 0;
	double oldTime = 0;
	params[0] = (void *)&infos;
	params[1] = (void *)&mlx;

	all(&infos, &mlx);
	mlx_hook(mlx.win, 2, (1L << 0), keypressed, (void *)params);
	mlx_loop(mlx.mlx_ptr);
}
