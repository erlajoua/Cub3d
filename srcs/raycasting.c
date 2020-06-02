/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:25:13 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:25:15 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	setdrawp(t_info *infos, t_cub *cub)
{
	infos->drawstart = -infos->lineheight / 2 + infos->resy / 2;
	if (infos->drawstart < 0)
		infos->drawstart = 0;
	infos->drawend = infos->lineheight / 2 + infos->resy / 2;
	if (infos->drawend >= infos->resy)
		infos->drawend = infos->resy - 1;
	infos->texnum = cub->parse.map[infos->mapx][infos->mapy] - 1;
	if (infos->side == 0)
		infos->wallx = infos->posy + infos->perpwalldist * infos->raydiry;
	else
		infos->wallx = infos->posx + infos->perpwalldist * infos->raydirx;
	infos->wallx -= floor(infos->wallx);
	infos->tex_x = (int)(infos->wallx * (double)infos->txtr[0].width);
	if (infos->side == 0 && infos->raydirx > 0)
		infos->tex_x = infos->txtr[0].width - infos->tex_x - 1;
	if (infos->side == 1 && infos->raydiry < 0)
		infos->tex_x = infos->txtr[0].width - infos->tex_x - 1;
	infos->step = 1.0 * infos->txtr[0].height / infos->lineheight;
	infos->texpos = (infos->drawstart - infos->resy / 2 +
	infos->lineheight / 2) * infos->step;
}

void	sidedistxy(t_info *infos)
{
	infos->hit = 0;
	if (infos->raydirx < 0)
	{
		infos->stepx = -1;
		infos->sidedistx = (infos->posx - infos->mapx) *
		infos->deltadistx;
	}
	else
	{
		infos->stepx = 1;
		infos->sidedistx = (infos->mapx + 1.0 - infos->posx) *
		infos->deltadistx;
	}
	if (infos->raydiry < 0)
	{
		infos->stepy = -1;
		infos->sidedisty = (infos->posy - infos->mapy) * infos->deltadisty;
	}
	else
	{
		infos->stepy = 1;
		infos->sidedisty = (infos->mapy + 1.0 - infos->posy) *
		infos->deltadisty;
	}
}

void	dda(t_info *infos, t_cub *cub)
{
	while (infos->hit == 0)
	{
		if (infos->sidedistx < infos->sidedisty)
		{
			// printf("Passage 0\n");
			infos->sidedistx += infos->deltadistx;
			infos->mapx += infos->stepx;
			infos->side = 0;
		}
		else
		{
			// printf("Passage 1 \n");
			infos->sidedisty += infos->deltadisty;
			infos->mapy += infos->stepy;
			infos->side = 1;
		}
		if (cub->parse.map[infos->mapx][infos->mapy] == '1')
			infos->hit = 1;
	}
	if (infos->side == 0)
		infos->perpwalldist = (infos->mapx - infos->posx +
	(1 - infos->stepx) / 2) / infos->raydirx;
	else
		infos->perpwalldist = (infos->mapy - infos->posy +
	(1 - infos->stepy) / 2) / infos->raydiry;
	infos->lineheight = (int)(infos->resy / infos->perpwalldist);
}

void	all(t_info *infos, t_mlx *mlx, t_cub *cub)
{
	infos->x = 0;
	while (infos->x < infos->resx)
	{
		raydirxy(infos);
		sidedistxy(infos);
		dda(infos, cub);
		draw(mlx, infos, cub);
		infos->zbuffer[infos->x] = infos->perpwalldist;
		infos->x++;
	}
	draw_sprite(infos, cub, mlx);
	if (cub->parse.save == 1)
	{
		cub->parse.save = 0;
		bitmap(mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

int		raycasting(t_mlx *mlx, t_info *infos, t_cub *cub)
{
	infos->txtr[0].img = mlx_xpm_file_to_image(mlx->mlx_ptr,
	cub->parse.west, &infos->txtr[0].width, &infos->txtr[0].height);
	infos->txtr[1].img = mlx_xpm_file_to_image(mlx->mlx_ptr,
	cub->parse.north, &infos->txtr[1].width, &infos->txtr[1].height);
	infos->txtr[2].img = mlx_xpm_file_to_image(mlx->mlx_ptr,
	cub->parse.east, &infos->txtr[2].width, &infos->txtr[2].height);
	infos->txtr[3].img = mlx_xpm_file_to_image(mlx->mlx_ptr,
	cub->parse.south, &infos->txtr[3].width, &infos->txtr[3].height);
	infos->txtr[4].img = mlx_xpm_file_to_image(mlx->mlx_ptr,
	cub->parse.sprite, &infos->txtr[4].width, &infos->txtr[4].height);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, infos->resx, infos->resy);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
	&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	if (!(infos->zbuffer = malloc(sizeof(double) * infos->resx)))
		ft_error("malloc zbuffer error");
	initvalue(infos, cub);
	infos->posx += 0.5;
	infos->posy += 0.5;
	all(infos, mlx, cub);
	return (1);
}
