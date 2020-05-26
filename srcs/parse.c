/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:28:44 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/26 13:36:56 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	want_save(t_cub *cub, int ac, char *av2)
{
	if (ac >= 3)
	{
		if (ft_strcmp(av2, "--save") == 0)
			cub->parse.save = 1;
		else
			ft_error("second argument is not --save");
	}
	else
	{
		cub->parse.save = 0;
	}
}

void	init_window(t_mlx *mlx, t_info *infos)
{
	mlx->mlx_ptr = mlx_init();
	mlx->img.width = infos->RESX;
	mlx->img.height = infos->RESY;
	mlx->win = mlx_new_window(mlx->mlx_ptr, infos->RESX, infos->RESY, "Cub3d");
}

void	ft_start(t_cub *cub)
{
	cub->parse.i = 0;
	cub->parse.strlen = 0;
	cub->parse.nbline = 0;
	cub->parse.side = '0';
	cub->parse.pos[0] = 0;
	cub->parse.pos[1] = 0;
	cub->parse.flag = 0;
}

int		main(int ac, char **av)
{
	void	*params[3];
	t_mlx	mlx;
	t_info	infos;
	t_cub	cub;

	ft_start(&cub);
	get_lines(&cub, &infos, av[1]);
	fill_sp(&cub);
	check_map(&cub);
	want_save(&cub, ac, av[2]);
	init_window(&mlx, &infos);
	params[0] = (void *)&infos;
	params[1] = (void *)&mlx;
	params[2] = (void *)&cub;
	raycasting(&mlx, &infos, &cub);
	free(cub.parse.north);
	free(cub.parse.south);
	free(cub.parse.east);
	free(cub.parse.west);
	free(cub.parse.sprite);
	mlx_hook(mlx.win, 2, (1L << 0), keypressed, (void *)params);
	mlx_hook(mlx.win, 17, (1L << 17), cross_destroy, (void *)(&params));
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
