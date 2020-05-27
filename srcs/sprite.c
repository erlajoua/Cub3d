/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:26:55 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:26:56 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	start_spr(t_info *infos)
{
	int			i;
	double		first;
	double		second;
	t_sprite	tmp;

	i = 0;
	while (i < infos->spr_nb && i + 1 != infos->spr_nb)
	{
		first = ((infos->posx - infos->sprite[i].x) *
				(infos->posx - infos->sprite[i].x)
				+ (infos->posy - infos->sprite[i].y) *
				(infos->posy - infos->sprite[i].y));
		second = ((infos->posx - infos->sprite[i + 1].x) *
				(infos->posx - infos->sprite[i + 1].x)
				+ (infos->posy - infos->sprite[i + 1].y) *
				(infos->posy - infos->sprite[i + 1].y));
		if (first < second)
		{
			tmp = infos->sprite[i];
			infos->sprite[i] = infos->sprite[i + 1];
			infos->sprite[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	get_nb_spr(t_info *infos, t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	infos->spr_nb = 0;
	while (cub->parse.map[x] && x <= cub->parse.nbline - 1)
	{
		y = 0;
		while (cub->parse.map[x][y])
		{
			if (cub->parse.map[x][y] == '2')
				infos->spr_nb++;
			y++;
		}
		x++;
	}
}

void	calc_spr2(t_info *infos, int i)
{
	infos->spr_x = infos->sprite[i].x - infos->posx;
	infos->spr_y = infos->sprite[i].y - infos->posy;
	infos->invdet = 1.0 / (infos->planex *
			infos->diry - infos->dirx * infos->planey);
	infos->transx = infos->invdet *
		(infos->diry * infos->spr_x - infos->dirx * infos->spr_y);
	infos->transy = infos->invdet *
		(-infos->planey * infos->spr_x + infos->planex * infos->spr_y);
	infos->sprscreen_x = (int)((infos->resx / 2) *
			(1 + infos->transx / infos->transy));
	infos->spr_h = abs((int)(infos->resy / infos->transy));
	infos->drawstart_y = -infos->spr_h / 2 + infos->resy / 2;
}

void	calc_spr(t_info *infos, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < infos->spr_nb)
	{
		calc_spr2(infos, i);
		if (infos->drawstart_y < 0)
			infos->drawstart_y = 0;
		infos->drawend_y = infos->spr_h / 2 + infos->resy / 2;
		if (infos->drawend_y >= infos->resy)
			infos->drawend_y = infos->resy - 1;
		infos->spr_w = abs((int)(infos->resx / infos->transy));
		infos->drawstart_x = -infos->spr_w / 2 + infos->sprscreen_x;
		if (infos->drawstart_x < 0)
			infos->drawstart_x = 0;
		infos->drawend_x = infos->spr_w / 2 + infos->sprscreen_x;
		if (infos->drawend_x >= infos->resx)
			infos->drawend_x = infos->resx - 1;
		infos->sprite[0].txt = infos->txtr[4].img;
		disp_spr(infos, mlx);
		i++;
	}
}

void	draw_sprite(t_info *infos, t_cub *cub, t_mlx *mlx)
{
	get_nb_spr(infos, cub);
	init_spr(infos, cub);
	start_spr(infos);
	calc_spr(infos, mlx);
	if (infos->spr_nb >= 1)
		free(infos->sprite);
}
