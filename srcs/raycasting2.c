/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:22:30 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:22:32 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	drawsky(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	int j;

	j = 0;
	while (j < infos->drawstart)
	{
		mlx->img.data[infos->x + j * infos->resx] = 256 * 256 *
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
		infos->resx)] = infos->hex;
		infos->drawend--;
	}
}

void	draw(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	int k;

	chose_color(infos);
	setdrawp(infos, cub);
	drawsky(mlx, infos, cub);
	k = infos->drawend;
	drawwall(mlx, infos);
	while (k < infos->resy)
	{
		mlx->img.data[infos->x + k * infos->resx] = 256 * 256 *
		cub->parse.floor_rgb[0] + 256 * cub->parse.floor_rgb[1] +
		cub->parse.floor_rgb[2];
		k++;
	}
}

void	initvalue(t_info *infos, t_cub *cub)
{
	infos->posx = cub->parse.pos[0];
	infos->posy = cub->parse.pos[1];
	infos->dirx = 0;
	infos->diry = 0;
	infos->planex = 0;
	infos->planey = 0;
	init_nw(infos, cub);
	init_se(infos, cub);
}

void	chose_color(t_info *infos)
{
	if (infos->side == 0)
	{
		if (infos->raydirx > 0)
			infos->infotxtr = 3;
		else
			infos->infotxtr = 1;
	}
	else if (infos->side == 1)
	{
		if (infos->raydiry < 0)
			infos->infotxtr = 0;
		else
			infos->infotxtr = 2;
	}
}
