#define screenWidth 1280
#define screenHeight 720
#define mapWidth 24
#define mapHeight 24
#include "cub.h"
#include <stdbool.h>

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
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

struct s_info{
	double posX;
	double posY;
	double moveSpeed;
	double dirX;
	double dirY;
};
typedef struct s_info t_info;

int	key_win1(int key, void *p)
{
	printf("KEY :: |%d|\n",key);

	bool x;
	x = false;

	void *t;
	t_info *infos;

	t = (void *)p;
	infos = p;

	if(key == 122) //up
	{
		printf("test");
		if(worldMap[(int)(infos->posX + infos->dirX * infos->moveSpeed)][(int)(infos->posY)] == false) 
		{
			printf("test if\n");
			infos->posX += infos->dirX * infos->moveSpeed;
		}
		if(worldMap[(int)(infos->posX)][(int)(infos->posY + infos->dirY * infos->moveSpeed)] == false) 
		{
			printf("autre \n");
			infos->posY += infos->dirY * infos->moveSpeed;
		}
		printf("KOKO: %lf", infos->posX);
	}
}

int main(void)
{
	t_info infos;
	t_mlx	mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, screenWidth, screenHeight, "Thomas!");

	infos.posX = 19, infos.posY = 22;  //15 15 so insane petit coin chaud au fond a gauche (dir -1 0)
	infos.dirX = -1, infos.dirY = 0; //initial direction vector
	
	infos.moveSpeed = 0.3;

	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	void *params;

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	//screen(screenWidth, screenHeight, 0, "Raycaster");

	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, screenWidth, screenHeight);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,&mlx.img.endian);
	mlx_clear_window(mlx.mlx_ptr, mlx.win);
	// while(!done())
	//{
	params = &infos;
		int x;
		int y = 0;
		x = 0;
		while (x < screenWidth)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
			double rayDirX = infos.dirX + planeX * cameraX;
			double rayDirY = infos.dirY + planeY * cameraX;
			//which box of the map we're in
			int mapX = (int)infos.posX;
			int mapY = (int)infos.posY;

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;
			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
			double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;


			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if(rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (infos.posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - infos.posX) * deltaDistX;
			}
			if(rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (infos.posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - infos.posY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if((sideDistY <= 0 || sideDistX >= 0) && (sideDistX < sideDistY))
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if(worldMap[mapX][mapY] > 0)
					hit = 1;
			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if(side == 0)
				perpWallDist = (mapX - infos.posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - infos.posY + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(screenHeight / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = 0;
			int drawEnd = 0;
			
			drawStart = -lineHeight / 2 + screenHeight / 2;
			if(drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + screenHeight / 2;
			if(drawEnd >= screenHeight)
				drawEnd = screenHeight - 1;
			int color;
			switch(worldMap[mapX][mapY])
			{
				case 1:  color = 0xFF0000;    break; //red
				case 2:  color = 0x00FF00;  break; //green
				default: color = 0xFFFF66; break; //yellow
			}

			//give x and y sides different brightness
			if(side == 1)
			{
				color = color / 2;
			}
			int count_w = 0;
			while (drawStart < drawEnd)
			{
				mlx.img.data[(int)x + (drawEnd * screenWidth)] = 0xFF0000;
				drawEnd--;
			}
			x++;
		}
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
		mlx_key_hook(mlx.win,key_win1,params);
	mlx_loop(mlx.mlx_ptr);
}
