#include "headers/cub.h"


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
