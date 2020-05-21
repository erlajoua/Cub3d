/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:26:01 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:26:02 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	init_nw(t_info *infos, t_cub *cub)
{
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
}

void	init_se(t_info *infos, t_cub *cub)
{
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

void	raydirxy(t_info *infos)
{
	infos->mapx = (int)infos->posx;
	infos->mapy = (int)infos->posy;
	infos->camerax = 2 * infos->x / (double)infos->RESX - 1;
	infos->raydirx = infos->dirx + infos->planex * infos->camerax;
	infos->raydiry = infos->diry + infos->planey * infos->camerax;
	infos->deltadistx = (infos->raydiry == 0) ? 0 :
	((infos->raydirx == 0) ? 1 : fabs(1 / infos->raydirx));
	infos->deltadisty = (infos->raydirx == 0) ? 0 :
	((infos->raydiry == 0) ? 1 : fabs(1 / infos->raydiry));
}
