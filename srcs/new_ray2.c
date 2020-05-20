#define mapWidth 24
#define mapHeight 24
#include "../headers/cub.h"

	char txt_rgb[8] = "0x00FF00";

void	chose_color(t_info *infos) 
{
	if (infos->side == 0) //EW
	{
		if (infos->raydirx > 0)
			infos->infotxtr = 0; //0
		else
			infos->infotxtr = 1; //1
	}
	else if (infos->side == 1) //NS
	{
		if (infos->raydiry < 0)
			infos->infotxtr = 2; //2
		else
			infos->infotxtr = 3; //3
	}
}

void	drawsky(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	int j = 0;
	while (j < infos->drawstart)
	{
		mlx->img.data[infos->x + j * infos->RESX] = 256 * 256 * cub->parse.ceiling_rgb[0] + 256 * cub->parse.ceiling_rgb[1] + cub->parse.ceiling_rgb[2];
		//mlx->img.data[infos->x + j * infos->RESX] = (int)0x00FF00;
		j++;
	}
}

void	setdrawp(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	infos->drawstart = -infos->lineHeight / 2 + infos->RESY / 2;
	if (infos->drawstart < 0)
		infos->drawstart = 0;
	infos->drawend = infos->lineHeight / 2 + infos->RESY / 2;
	if (infos->drawend >= infos->RESY)
		infos->drawend = infos->RESY - 1;
	infos->texnum = cub->parse.map[infos->mapx][infos->mapy] - 1;
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
	infos->texpos = (infos->drawstart - infos->RESY / 2 + infos->lineHeight / 2) * infos->step;
}

void	drawwall(t_mlx *mlx, t_info *infos)
{
	// infos->dataimg = malloc(sizeof(int) * 100);
	// printf("xtt : %d\n", infos->txtr[1].height);
	while (infos->drawstart < infos->drawend)
	{
		infos->tex_y = (int)infos->texpos & (infos->txtr[infos->infotxtr].height - 1);
				// printf("1super!\n");
		infos->texpos += infos->step;
				// printf("2super!\n");
					// printf("xtt : %d\n", infos->infotxtr);
		infos->dataimg = (int *)mlx_get_data_addr(infos->txtr[infos->infotxtr].img, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
					// printf("3super!\n");

		infos->hex = infos->dataimg[infos->tex_y * infos->txtr[infos->infotxtr].width + infos->tex_x];
				// printf("4super!\n");

		mlx->img.data[infos->x + (infos->drawend * infos->RESX)] = infos->hex;
				// printf("5super!\n");

		infos->drawend--;
	}
}

void	draw(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	// int infos->color;
	int k;

	chose_color(infos);
	setdrawp(mlx, infos, cub);
	drawsky(mlx, infos, cub);
	k = infos->drawend;
	drawwall(mlx, infos);
	// printf("2super!\n");

	//drawfloor
	while (k < infos->RESY)
	{
		mlx->img.data[infos->x + k * infos->RESX] = 256 * 256 * cub->parse.floor_rgb[0] +  256 * cub->parse.floor_rgb[1] + cub->parse.floor_rgb[2];
		//mlx->img.data[infos->x + k * infos->RESX] = 256 * 256 * 15 +  256 * 56 + 15;
		k++;
	}
}

void raydirxy(t_info *infos, t_cub *cub)
{
	infos->mapx = (int)infos->posx;
	infos->mapy = (int)infos->posy;
	infos->camerax = 2 * infos->x / (double)infos->RESX - 1;
	infos->raydirx = infos->dirx + infos->planex * infos->camerax;
	infos->raydiry = infos->diry + infos->planey * infos->camerax;
	infos->deltadistx = (infos->raydiry == 0) ? 0 : ((infos->raydirx == 0) ? 1 : fabs(1 / infos->raydirx));
	infos->deltadisty = (infos->raydirx == 0) ? 0 : ((infos->raydiry == 0) ? 1 : fabs(1 / infos->raydiry));
}

void sidedistxy(t_info *infos, t_cub *cub)
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

void dda(t_info *infos, t_cub *cub)
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
		if (cub->parse.map[infos->mapx][infos->mapy] == '1') //|| cub->parse.map[infos->mapx][infos->mapy] == '2') //faire attention
			infos->hit = 1;
	}
	if (infos->side == 0)
		infos->perpwalldist = (infos->mapx - infos->posx + (1 - infos->stepx) / 2) / infos->raydirx;
	else
		infos->perpwalldist = (infos->mapy - infos->posy + (1 - infos->stepy) / 2) / infos->raydiry;
	infos->lineHeight = (int)(infos->RESY / infos->perpwalldist);
}

void all(t_info *infos, t_mlx *mlx, t_cub *cub)
{
	infos->x = 0;
	while (infos->x < infos->RESX)
	{
		raydirxy(infos, cub);
		sidedistxy(infos, cub);
		dda(infos, cub);
		draw(mlx, infos, cub);
		infos->zbuffer[infos->x] = infos->perpwalldist;
		infos->x++;
	}
	draw_sprite(infos, cub, mlx);
	if(cub->parse.save == 1)
	{
		cub->parse.save = 0;
		bitmap(mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

void initializeValues(t_mlx *mlx, t_info *infos, t_cub *cub)
{

	infos->posx = cub->parse.pos[0], infos->posy = cub->parse.pos[1];

	infos->dirx = 0;
	infos->diry = 0;
	infos->planex = 0;
	infos->planey = 0;
	if(cub->parse.side == 'N') //good
	{
		// printf("super!\n");
		infos->dirx = -1;
		infos->diry = 0;
		infos->planex = 0;
		infos->planey = -0.66;
		infos->savedir = -1;
	}
	if(cub->parse.side == 'W') //good
	{
		infos->dirx = 0;
		infos->diry = 1;
		infos->planex = -0.66;
		infos->planey = 0;
		infos->savedir = -1;
	}
	if(cub->parse.side == 'S') //good
	{
		infos->dirx = 1;
		infos->diry = 0;
		infos->planex = 0;
		infos->planey = 0.66;
		infos->savedir = 1;
	}
	if(cub->parse.side == 'E') //good
	{
		infos->dirx = 0;
		infos->diry = -1;
		infos->planex = 0.66;
		infos->planey = 0;
		infos->savedir = 1;
	}
}

void	updown(t_mlx *mlx, t_info *infos, t_cub *cub, int key)
{
	
		char dirside;

		dirside = cub->parse.side;
		infos->mvspeed *= (key == 115) ? -1 : 1;
		if (cub->parse.map[(int)(infos->posx + infos->dirx * infos->mvspeed)][(int)(infos->posy)] == '0'
		|| cub->parse.map[(int)(infos->posx + infos->dirx * infos->mvspeed)][(int)(infos->posy)] == dirside)
			infos->posx += infos->dirx * infos->mvspeed;
		if (cub->parse.map[(int)(infos->posx)][(int)(infos->posy + infos->diry * infos->mvspeed)] == '0'
		|| cub->parse.map[(int)(infos->posx)][(int)(infos->posy + infos->diry * infos->mvspeed)] == dirside)
			infos->posy += infos->diry * infos->mvspeed;
}

void	mv_lr(t_mlx *mlx, t_info *infos, t_cub *cub, int key)
{
		char dirside;

		dirside = cub->parse.side;
		//infos->mvspeed *= -infos->savedir;
		infos->mvspeed *= (key == 100) ? -1 : 1;
		if (cub->parse.map[(int)(infos->posx)][(int)(infos->posy - infos->dirx * infos->mvspeed)] == '0'
		|| cub->parse.map[(int)(infos->posx)][(int)(infos->posy - infos->dirx * infos->mvspeed)] == dirside)
			infos->posy -= infos->dirx * infos->mvspeed;
		if (cub->parse.map[(int)(infos->posx + infos->mvspeed * infos->diry)][(int)(infos->posy)] == '0'
		|| cub->parse.map[(int)(infos->posx + infos->mvspeed * infos->diry)][(int)(infos->posy)] == dirside)
			infos->posx += infos->diry * infos->mvspeed;
}

void	cam_lr(t_mlx *mlx, t_info *infos, t_cub *cub, int key)
{
		double olddirx;
		double oldplanex;
		double angle;
		angle = (D_PI / 30) * -1;
		angle *= (key == 65363) ? -1 : 1;

		olddirx = infos->dirx;
		oldplanex = infos->planex;
		infos->dirx = infos->dirx * cos(angle) - infos->diry * sin(angle);
		infos->diry = olddirx * sin(angle) + infos->diry * cos(angle);
		infos->planex = infos->planex * cos(angle) - infos->planey * sin(angle);
		infos->planey = oldplanex * sin(angle) + infos->planey * cos(angle);
}

int keypressed(int key, void *p)
{
	void **recup;
	t_info *infos;
	t_mlx *mlx;
	t_cub *cub;
	
	recup = (void **)p;
	infos = recup[0];
	mlx = recup[1];
	cub = recup[2];
	if (key == 65307)
		exit(0);
	infos->mvspeed = 0.4;
	if (key == 122 || key == 115) //up & down
	{
		updown(mlx, infos, cub, key);	
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	}
	else if (key == 113 || key == 100) //left & right
	{
		mv_lr(mlx, infos, cub, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	}
	else if (key == 65361 || key == 65363) //camera left & right
	{
		cam_lr(mlx, infos, cub, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	}
	return (1);
}

int		raycasting(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	/*FIN VIA PARSING*/
	//GESTION D"ERREUR A FAIRE
	infos->txtr[0].img = mlx_xpm_file_to_image(mlx->mlx_ptr, cub->parse.north, &infos->txtr[0].width, &infos->txtr[0].height); //north.xpm
	infos->txtr[1].img = mlx_xpm_file_to_image(mlx->mlx_ptr, cub->parse.south, &infos->txtr[1].width, &infos->txtr[1].height); //south.xpm
	infos->txtr[2].img = mlx_xpm_file_to_image(mlx->mlx_ptr, cub->parse.west, &infos->txtr[2].width, &infos->txtr[2].height); //weast.xpm
	infos->txtr[3].img = mlx_xpm_file_to_image(mlx->mlx_ptr, cub->parse.east, &infos->txtr[3].width, &infos->txtr[3].height); //east.xpm
	infos->txtr[4].img = mlx_xpm_file_to_image(mlx->mlx_ptr, cub->parse.sprite, &infos->txtr[4].width, &infos->txtr[4].height); //sprc.xpm

	//infos->tximg = mlx_xpm_file_to_image(mlx->mlx_ptr, "bricks.xpm", &infos->txwidth, &infos->txheight);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, infos->RESX, infos->RESY);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);

	if (!(infos->zbuffer = malloc(sizeof(double) * infos->RESX)))
		ft_error("malloc zbuffer error");
	
	initializeValues(mlx, infos, cub);
	
	//sil y a un mur pile sur le joueur
	infos->posx += 0.5;
	infos->posy += 0.5;
	
	all(infos, mlx, cub);

	// printf("debug\n");
	return (1);
}
