/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:57:49 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/11 10:57:50 by erlajoua         ###   ########.fr       */
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
		infos->planey = 0.66;
	}
	if (cub->parse.side == 'W')
	{
		infos->dirx = 0;
		infos->diry = -1;
		infos->planex = -0.66;
		infos->planey = 0;
	}
}

void	init_se(t_info *infos, t_cub *cub)
{
	if (cub->parse.side == 'S')
	{
		infos->dirx = 1;
		infos->diry = 0;
		infos->planex = 0;
		infos->planey = -0.66;
	}
	if (cub->parse.side == 'E')
	{
		infos->dirx = 0;
		infos->diry = 1;
		infos->planex = 0.66;
		infos->planey = 0;
	}
}

void	raydirxy(t_info *infos)
{
	infos->mapx = (int)infos->posx;
	infos->mapy = (int)infos->posy;
	infos->camerax = 2 * infos->x / (double)infos->resx - 1;
	infos->raydirx = infos->dirx + infos->planex * infos->camerax;
	infos->raydiry = infos->diry + infos->planey * infos->camerax;
	if (infos->raydiry == 0)
		infos->deltadistx = 0;
	else if (infos->raydirx == 0)
		infos->deltadistx = 1;
	else
		infos->deltadistx = fabs(1 / infos->raydirx);
	if (infos->raydirx == 0)
		infos->deltadisty = 0;
	else if (infos->raydiry == 0)
		infos->deltadisty = 1;
	else
		infos->deltadisty = fabs(1 / infos->raydiry);
}
