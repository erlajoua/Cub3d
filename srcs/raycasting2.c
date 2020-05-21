#include "../headers/cub.h"

void	drawsky(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	int j;

	j = 0;
	while (j < infos->drawstart)
	{
		mlx->img.data[infos->x + j * infos->RESX] = 256 * 256 *
		cub->parse.ceiling_rgb[0] + 256 * cub->parse.ceiling_rgb[1] +
		cub->parse.ceiling_rgb[2];
		j++;
	}
}

void	drawwall(t_mlx *mlx, t_info *infos)
{
	while (infos->drawstart < infos->drawend)
	{
		infos->tex_y = (int)infos->texpos &
		(infos->txtr[infos->infotxtr].height - 1);
		infos->texpos += infos->step;
		infos->dataimg =
		(int *)mlx_get_data_addr(infos->txtr[infos->infotxtr].img,
		&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
		infos->hex = infos->dataimg[infos->tex_y *
		infos->txtr[infos->infotxtr].width + infos->tex_x];
		mlx->img.data[infos->x + (infos->drawend *
		infos->RESX)] = infos->hex;
		infos->drawend--;
	}
}

void	draw(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	int k;

	chose_color(infos);
	setdrawp(mlx, infos, cub);
	drawsky(mlx, infos, cub);
	k = infos->drawend;
	drawwall(mlx, infos);
	while (k < infos->RESY)
	{
		mlx->img.data[infos->x + k * infos->RESX] = 256 * 256 *
		cub->parse.floor_rgb[0] +  256 * cub->parse.floor_rgb[1] +
		cub->parse.floor_rgb[2];
		k++;
	}
}

void	initvalue(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	infos->posx = cub->parse.pos[0];
	infos->posy = cub->parse.pos[1];
	infos->dirx = 0;
	infos->diry = 0;
	infos->planex = 0;
	infos->planey = 0;
	if (cub->parse.side == 'N')
	{
		infos->dirx = -1;
		infos->diry = 0;
		infos->planex = 0;
		infos->planey = -0.66;
		infos->savedir = -1;
	}
	if (cub->parse.side == 'W')
	{
		infos->dirx = 0;
		infos->diry = 1;
		infos->planex = -0.66;
		infos->planey = 0;
		infos->savedir = -1;
	}
	if (cub->parse.side == 'S')
	{
		infos->dirx = 1;
		infos->diry = 0;
		infos->planex = 0;
		infos->planey = 0.66;
		infos->savedir = 1;
	}
	if (cub->parse.side == 'E')
	{
		infos->dirx = 0;
		infos->diry = -1;
		infos->planex = 0.66;
		infos->planey = 0;
		infos->savedir = 1;
	}
}

void	chose_color(t_info *infos)
{
	if (infos->side == 0)
	{
		if (infos->raydirx > 0)
			infos->infotxtr = 0;
		else
			infos->infotxtr = 1;
	}
	else if (infos->side == 1)
	{
		if (infos->raydiry < 0)
			infos->infotxtr = 2;
		else
			infos->infotxtr = 3;
	}
}
