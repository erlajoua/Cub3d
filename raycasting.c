#include "cub.h"
#include <math.h>
#define WIN_H 800
#define WIN_W 600
#define mapWidth 24
#define mapHeight 24

int map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,5,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main(void)
{
	//Initialisation position et direction du joueur
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;

	//Initialisation variables FPS
	double time = 0;
	double oldTime = 0;

	//Creer la window
	while (1)
	{
		printf("test\n");
		int x = 0;
		double w = 10;
		while (x <= (int)w)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / w - 1;
			// printf("cameraX : %lf\n", cameraX);
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
			// printf("rayDirX : %lf | rayDirY : %f\n", rayDirX, rayDirY);

			int mapX = (int)posX;
			int mapY = (int)posY;
			// printf("posX  : %d | posY : %d\n\n", mapX, mapY);

			double sideDistX;
      		double sideDistY;

			// double deltaDistX = fabs(1 / rayDirX);
      		// double deltaDistY = fabs(1 / rayDirY);
      		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
      		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));

      		// printf("deltaDistX (%lf) \n deltaDistY (%lf)\n", deltaDistX, deltaDistY);
      		double perpWallDist;

			int stepX;
      		int stepY;

			int hit = 0;
			int side;
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
				printf("IF : sideDistX : %lf\n", sideDistX);
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
				printf("ELSE : sideDistX : %lf\n", sideDistX);
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
				printf("IF : sideDistY : %lf\n", sideDistY);
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
				printf("ELSE : sideDistY : %lf\n", sideDistY);
			}
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
					//printf("Vers la droite || gauche \n");
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
					//printf("Vers le haut || bas\n");
				}
				//Check if ray has hit a wall
				//printf("map[mapX][mapY] : %d\n", map[mapX][mapY]);
				if (map[mapX][mapY] > 0)
					hit = 1;
			}
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      		else
			  	perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
			//printf("Value perpWallDist : %lf\n", perpWallDist);

			int lineHeight = (int)(WIN_H / perpWallDist);
			//printf("lineHeight : %d\n", lineHeight);
			int drawStart = -lineHeight / 2 + WIN_H / 2;
			if(drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + WIN_H / 2;
			if(drawEnd >= WIN_H)
				drawEnd = WIN_H - 1;
			//choose wall color
			int color;
			switch(map[mapX][mapY])
			{
				case 1:  color = 0xFF0000;  break; //red
				case 2:  color = 0x2FFF00;  break; //green
				case 3:  color = 0x0079F2;   break; //blue
				case 4:  color = 0xFFFFFF;  break; //white
				default: color = 0xF8FC00; break; //yellow
			}

			//give x and y sides different brightness
			if (side == 1)
			{
				color = color / 2;
			}

			//draw the pixels of the stripe as a vertical line
			//verLine(x, drawStart, drawEnd, color);
			x++;
		}
		oldTime = time;
		//time = getTicks();
		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		/*printf("%lf", (1.0 / frameTime)); //FPS counter
		redraw();
		cls();
		*/
		double moveSpeed = frameTime * 5.0;
    	double rotSpeed = frameTime * 3.0;
		getchar();
	}
	return (0);
}
