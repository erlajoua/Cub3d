
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#include "cub.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main(void)
{
  double posX = 22, posY = 12;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame

  //screen(screenWidth, screenHeight, 0, "Raycaster");
  t_mlx	mlx;
  mlx.mlx_ptr = mlx_init();
  mlx.win = mlx_new_window(mlx.mlx_ptr, screenWidth, screenHeight, "Thomas!");
  mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, screenWidth, screenHeight);
  mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,&mlx.img.endian);
  // while(!done())
  //{
  int x = 0;
  while (x < screenWidth)
  {
	//calculate ray position and direction
	double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
	double rayDirX = dirX + planeX * cameraX;
	double rayDirY = dirY + planeY * cameraX;
	//which box of the map we're in
	int mapX = (int)posX;
	int mapY = (int)posY;

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
	  sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
	  stepX = 1;
	  sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if(rayDirY < 0)
	{
	  stepY = -1;
	  sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
	  stepY = 1;
	  sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
	//perform DDA
	while (hit == 0)
	{
	  //jump to next map square, OR in x-direction, OR in y-direction
	  if(sideDistX < sideDistY)
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
	  perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
	else
	  perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

	//Calculate height of line to draw on screen
	int lineHeight = (int)(screenHeight / perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	int drawStart = -lineHeight / 2 + screenHeight / 2;
	if(drawStart < 0)
	  drawStart = 0;
	int drawEnd = lineHeight / 2 + screenHeight / 2;
	if(drawEnd >= screenHeight)
	  drawEnd = screenHeight - 1;

	//choose wall color
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
	int count_w = -1;
	int count_h = -1;
	if(x <= 10)
		printf("DRAWSTART : |%d| && DRAWEND : |%d|\n",drawStart, drawEnd);
	while (++count_w < screenWidth)
	{
		count_h = -1;
		while (++count_h < screenHeight)
		{
			if(drawEnd > drawStart)
			{
				mlx.img.data[count_w + count_h * drawStart] = 0x03B6FC;
			}
			//X position + 4 * Line size * Y position
			//mlx.img.data[count_h * screenWidth + count_w] = 0;
			drawStart++;
		}
	}
	/*mlx.img.data[drawStart * x] = 0xFFFFFF;
		mlx.img.data[drawEnd * x] = 0x00FF00;*/
	//draw the pixels of the stripe as a vertical line
	//verLine(x, drawStart, drawEnd, color);
	x++;
  }
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);/*
  //timing for input and FPS counter
  oldTime = time;
  time = getTicks();
  double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
  print(1.0 / frameTime); //FPS counter
  redraw();
  cls();

  //speed modifiers
  double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
  double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
  readKeys();
  //move forward if no wall in front of you
  if(keyDown(SDLK_UP))
  {
	if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
	if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
  }
  //move backwards if no wall behind you
  if(keyDown(SDLK_DOWN))
  {
	if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
	if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
  }
  //rotate to the right
  if(keyDown(SDLK_RIGHT))
  {
	//both camera direction and camera plane must be rotated
	double oldDirX = dirX;
	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	double oldPlaneX = planeX;
	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
  }
  //rotate to the left
  if(keyDown(SDLK_LEFT))
  {
	//both camera direction and camera plane must be rotated
	double oldDirX = dirX;
	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	double oldPlaneX = planeX;
	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
  }*/
  // }
}
