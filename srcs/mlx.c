/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:11:29 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 22:11:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	free_esc(void *p)
{
	void	**recup;
	t_cub	*cub;
	t_info	*infos;
	t_mlx	*mlx;

	recup = (void **)p;
	cub = recup[2];
	mlx = recup[1];
	infos = recup[0];
	free_map(cub);
	free_mlx(mlx, infos);
	exit(0);
}

void	free_mlx(t_mlx *mlx, t_info *infos)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	mlx_destroy_image(mlx->mlx_ptr, infos->txtr[0].img);
	mlx_destroy_image(mlx->mlx_ptr, infos->txtr[1].img);
	mlx_destroy_image(mlx->mlx_ptr, infos->txtr[2].img);
	mlx_destroy_image(mlx->mlx_ptr, infos->txtr[3].img);
	mlx_destroy_image(mlx->mlx_ptr, infos->txtr[4].img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(infos->zbuffer);
	free(mlx->mlx_ptr);
}

