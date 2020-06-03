/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:03:53 by tsarafia          #+#    #+#             */
/*   Updated: 2020/06/03 21:24:31 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

void	free_stuff(t_cub *cub)
{
	free(cub->parse.south);
	free(cub->parse.east);
	free(cub->parse.north);
	free(cub->parse.west);
	free(cub->parse.sprite);
}

int	expose_hook(void *params)
{
	void	**recup;

	t_info		*infos;
	t_mlx		*mlx;
	t_cub		*cub;
	recup = (void **)params;
	infos = recup[0];
	mlx = recup[1];
	cub = recup[2];	
	all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	return 0;
}

int		main(int ac, char **av)
{
	void	*params[3];
	t_mlx	mlx;
	t_info	infos;
	t_cub	cub;

	if (ac >= 2)
		check_ext(av[1], ".cub");
	else
		ft_error("No map");
	ft_start(&cub);
	get_lines(&cub, &infos, av[1]);
	fill_sp(&cub);
	check_map(&cub);
	want_save(&cub, ac, av);
	init_window(&cub, &mlx, &infos);
	params[0] = (void *)&infos;
	params[1] = (void *)&mlx;
	params[2] = (void *)&cub;
	raycasting(&mlx, &infos, &cub);
	free_stuff(&cub);
	
	
	mlx_hook(mlx.win, 2, (1L << 0), keypressed, (void *)params);
	mlx_hook(mlx.win, 17, (1L << 17), cross_destroy, (void *)(&params));
	
	mlx_expose_hook(mlx.win, expose_hook, (void *)params);
	mlx_loop(mlx.mlx_ptr);
	printf("WTF!!!\n");
	return (0);
}
