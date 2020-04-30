#define screenWidth 800
#define screenHeight 600
#define mapWidth 24
#define mapHeight 24
#include "cub.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

struct s_info{
	double posX;
	double posY;
	double moveSpeed;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double rayDirX;
	double rayDirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int side;
	int hit;
	int mapX;
	int mapY;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int x;
	int thomas;
	double oldDirX;
	double oldPlaneX;
	double saveDir;
};
typedef struct s_info t_info;

void	ft_draw(t_mlx *mlx, t_info *infos)
{
	int color;
	if (infos->side == 0)//EW
	{
		if (infos->rayDirX > 0)
			color = (int)0xFFFF00; //jaune
		else
			color = (int)0x00FF00;
	}
	else if (infos->side == 1) //NS
	{
		if (infos->rayDirY < 0)
			color = (int)0xFFFFFF; //gris
		else
			color = (int)0xFF0000;
	}
	infos->drawStart = -infos->lineHeight / 2 + screenHeight / 2;
	if(infos->drawStart < 0)
		infos->drawStart = 0;
	infos->drawEnd = infos->lineHeight / 2 + screenHeight / 2;
	if(infos->drawEnd >= screenHeight)
		infos->drawEnd = screenHeight - 1;
	
	for(int j = 0; j < infos->drawStart; j++)
	{
		mlx->img.data[infos->x + j * screenWidth] = (int)0x050E85;
	}
	int k = infos->drawEnd;
	while (infos->drawStart < infos->drawEnd)
	{
		mlx->img.data[infos->x + (infos->drawEnd * screenWidth)] = color;
		infos->drawEnd--;
	}
	for(k; k < screenHeight; k++)
	{
		mlx->img.data[infos->x + k * screenWidth] = (int)0x2B1B14;
	}
}


void	ft_raydirXY(t_info *infos)
{
	infos->mapX = (int)infos->posX;
	infos->mapY = (int)infos->posY;

	infos->cameraX = 2 * infos->x / (double)screenWidth - 1;
			
	infos->rayDirX = infos->dirX + infos->planeX * infos->cameraX;
	infos->rayDirY = infos->dirY + infos->planeY * infos->cameraX;

	infos->deltaDistX = (infos->rayDirY == 0) ? 0 : ((infos->rayDirX == 0) ? 1 : fabs(1 / infos->rayDirX));
	infos->deltaDistY = (infos->rayDirX == 0) ? 0 : ((infos->rayDirY == 0) ? 1 : fabs(1 / infos->rayDirY));
}

void	ft_sideDistXY(t_info *infos)
{
	infos->hit = 0;
	if(infos->rayDirX < 0)
	{
		infos->stepX = -1;
		infos->sideDistX = (infos->posX - infos->mapX) * infos->deltaDistX;
	}
	else
	{
		infos->stepX = 1;
		infos->sideDistX = (infos->mapX + 1.0 - infos->posX) * infos->deltaDistX;
	}
	if(infos->rayDirY < 0)
	{
		infos->stepY = -1;
		infos->sideDistY = (infos->posY - infos->mapY) * infos->deltaDistY;
	}
	else
	{
		infos->stepY = 1;
		infos->sideDistY = (infos->mapY + 1.0 - infos->posY) * infos->deltaDistY;
	}
}

void	ft_dda(t_info *infos)
{
	while (infos->hit == 0)
	{
		if(infos->sideDistX < infos->sideDistY)
		{
			infos->sideDistX += infos->deltaDistX;
			infos->mapX += infos->stepX;
			infos->side = 0;
		}
		else
		{
			infos->sideDistY += infos->deltaDistY;
			infos->mapY += infos->stepY;
			infos->side = 1;
		}
		if(worldMap[infos->mapX][infos->mapY] > 0)
			infos->hit = 1;
	}
	if(infos->side == 0)
		infos->perpWallDist = (infos->mapX - infos->posX + (1 - infos->stepX) / 2) / infos->rayDirX;
	else
		infos->perpWallDist = (infos->mapY - infos->posY + (1 - infos->stepY) / 2) / infos->rayDirY;
	infos->lineHeight = (int)(screenHeight / infos->perpWallDist);
}


void ft_all(t_info *infos, t_mlx *mlx)
{
	infos->x = 0;
	while (infos->x < screenWidth)
	{
		ft_raydirXY(infos);
		ft_sideDistXY(infos);
		ft_dda(infos);
		ft_draw(mlx, infos);
		infos->x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

void	initializeValues(t_mlx *mlx, t_info *infos)
{
	infos->posX = 4, infos->posY = 3;
	infos->dirX = 0, infos->dirY = 1;
	infos->planeX = 0.66, infos->planeY = 0;

	if(infos->dirY == 0)
	{
		if(infos->dirX < 0)
		{
			infos->saveDir = 1; //qd inversé
		}
		else if(infos->dirX > 0)
		{
			infos->saveDir = -1; //good
		}
	}
	else if(infos->dirX == 0)
	{
		if(infos->dirY < 0)
		{
			infos->saveDir = -1; //DJQZIDQZOJ
		}
		else if(infos->dirY > 0)
		{
			infos->saveDir = 1; //QD inversé
		}
	}

	infos->moveSpeed = 0.1;
}

int	keypressed(int key, void *p)
{
	void **recup;
	t_info *infos;
	t_mlx *mlx;

	recup = (void **)p;

	infos = recup[0];
	mlx = recup[1];
	if(key == 65307)
	{
		exit(0);
	}
	infos->moveSpeed = 0.3;
	if(key == 122 || key == 115)
	{
		//infos->moveSpeed *= infos->saveDir;
		infos->moveSpeed *= (key == 115) ? -1 : 1;
		if(worldMap[(int)(infos->posX + infos->dirX * infos->moveSpeed)][(int)(infos->posY)] == 0) 
		{
			infos->posX += infos->dirX * infos->moveSpeed;
		}
		if(worldMap[(int)(infos->posX)][(int)(infos->posY + infos->dirY * infos->moveSpeed)] == 0) 
		{
			infos->posY += infos->dirY * infos->moveSpeed;
		}
		ft_all(((t_info *)recup[0]), ((t_mlx *)recup[1]));
	}
	else if(key == 113 || key == 100) //left right
	{
		infos->moveSpeed *= -infos->saveDir;
		infos->moveSpeed *= (key == 100) ? -1 : 1;

		if (worldMap[(int)(infos->posX)][(int)(infos->posY - infos->dirX * infos->moveSpeed)] == 0)
        	infos->posY -= infos->dirX * infos->moveSpeed;
    	if (worldMap[(int)(infos->posX + infos->moveSpeed * infos->dirY)][(int)(infos->posY)] == 0)
        	infos->posX += infos->dirY * infos->moveSpeed;
		ft_all(((t_info *)recup[0]), ((t_mlx *)recup[1]));
	}
	else if(key == 65361 || key == 65363) //fleche gauche
	{	
		double    olddirx;
		double    oldplanex;
		double    angle;
		
		angle = 3.14159265358979323846 / 30 * infos->saveDir;
		angle *= (key == 65363) ? -1 : 1;
		
		olddirx = infos->dirX;
		oldplanex = infos->planeX;
		infos->dirX = infos->dirX * cos(angle) - infos->dirY * sin(angle);
		infos->dirY = olddirx * sin(angle) + infos->dirY * cos(angle);
		infos->planeX = infos->planeX * cos(angle) - infos->planeY * sin(angle);
		infos->planeY = oldplanex * sin(angle) + infos->planeY * cos(angle);
		ft_all(((t_info *)recup[0]), ((t_mlx *)recup[1]));
	}
}

int main(void)
{
	t_info  infos;
	t_mlx	mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, screenWidth, screenHeight, "Thomas!");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, screenWidth, screenHeight);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,&mlx.img.endian);

	initializeValues(&mlx, &infos);

	void *params[2];
	double time = 0;
	double oldTime = 0;
	params[0] = (void *)&infos;
	params[1] = (void *)&mlx;
	

	ft_all(&infos, &mlx);
	mlx_hook(mlx.win, 2, (1L << 0), keypressed, (void *)params);
	mlx_loop(mlx.mlx_ptr);
}
