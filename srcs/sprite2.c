/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:26:59 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:26:59 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	alloc_spr(t_info *infos)
{
	if (infos->spr_nb >= 1)
	{
		infos->sprite = (t_sprite *)malloc(sizeof(t_sprite) * infos->spr_nb);
		if (!infos->sprite)
			ft_error("error malloc number sprite");
	}
}

void	init_spr(t_info *infos, t_cub *cub)
{
	int x;
	int y;
	int nb;

	y = 0;
	nb = 0;
	alloc_spr(infos);
	init_val_spr(infos, cub);
	while (cub->parse.map[y] && y <= cub->parse.nbline - 1)
	{
		x = 0;
		while (cub->parse.map[y][x])
		{
			if (cub->parse.map[y][x] == '2')
			{
				infos->sprite[nb].x = (double)y + 0.5;
				infos->sprite[nb].y = (double)x + 0.5;
				infos->sprite[nb].txt = infos->txtr[4].img;
				nb++;
			}
			x++;
		}
		y++;
	}
}

void	disp_spr2(t_info *infos, t_mlx *mlx, int txtr_y, int i)
{
	int j;

	j = infos->drawstart_y;
	while (j < infos->drawend_y)
	{
		infos->drawstart = j *
		256 - infos->resy * 128 + infos->spr_h * 128;
		txtr_y = ((infos->drawstart *
		infos->txtr[4].height) / infos->spr_h) / 256;
		if (!(infos->datatest = (int *)mlx_get_data_addr(infos->sprite[0].txt,
		&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
			ft_error("datatest get data address");
		infos->res = infos->datatest[txtr_y * 64 + infos->txt];
		if (infos->res && 0x00FFFFFF != 0)
			mlx->img.data[j * infos->resx + i] = infos->res;
		j++;
	}
}

void	disp_spr(t_info *infos, t_mlx *mlx)
{
	int i;
	int txtr_y;

	i = 0;
	txtr_y = 0;
	i = infos->drawstart_x;
	while (i < infos->drawend_x)
	{
		infos->txt = (int)(256 * (i - (-infos->spr_w / 2 + infos->sprscreen_x))
		* infos->txtr[4].width / infos->spr_w) / 256;
		if (infos->transy > 0 && i > 0 && i < infos->resx
		&& infos->transy < infos->zbuffer[i])
		{
			disp_spr2(infos, mlx, txtr_y, i);
		}
		i++;
	}
}
