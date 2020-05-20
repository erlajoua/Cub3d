#include "../headers/cub.h"

void	floor(t_mlx *mlx, t_info *infos)
{
	for(int y = 0; y < WIN_H; y++)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float raydirx0 = infos->dirx - infos->planex;
		float raydiry0 = infos->diry - infos->planey;
		float raydirx1 = infos->dirx + infos->planex;
		float raydiry1 = infos->diry + infos->planey;

		// Current y position compared to the center of the screen (the horizon)
		int p = y - screenHeight / 2;

		// Vertical position of the camera.
		float pos_z = 0.5 * screenHeight;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float row_dist = pos_z / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floor_stepx = row_dist * (raydirx1 - raydirx0) / screenWidth;
		float floor_stepy = row_dist * (raydiry1 - raydiry0) / screenWidth;

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floor_x = infos->posx + row_dist * raydirx0;
		float floor_y = infos->posy + row_dist * raydiry0;

		for(int x = 0; x < screenWidth; ++x)
		{
				// the cell coord is simply got from the integer parts of floor_x and floor_y
				int cell_x = (int)(floor_x);
				int cell_y = (int)(floor_y);

				// get the texture coordinate from the fractional part
				int tx = (int)(infos->txwidth * (floor_x - cellx)) & (infos->txwidth - 1);
				int ty = (int)(infos->txheight * (floor_y - cell_y)) & (infos->txheight - 1);

				floor_x += floor_stepx; 
				floor_y += floor_stepy;

			/*
				infos->dataimg = (int *)mlx_get_data_addr(infos->txtr[infos->infotxtr].img, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
				infos->hex = infos->dataimg[infos->tex_y * infos->txtr[infos->infotxtr].width + infos->tex_x];
				mlx->img.data[infos->x + (infos->drawend * WIN_W)] = infos->hex;
			*/
				// choose texture and draw the pixel
				int floorTexture = 3;
				int ceilingTexture = 6;
				Uint32 color;

				// floor
				color = texture[floorTexture][infos->txwidth * ty + tx];
				buffer[y][x] = color;

				//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
				color = texture[ceilingTexture][infos->txwidth * ty + tx];
				buffer[screenHeight - y - 1][x] = color;
		}
	}
}

