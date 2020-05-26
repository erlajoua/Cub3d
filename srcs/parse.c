/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:28:44 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/23 12:16:59 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"
// #include "bitmap.c"
// #include "keypress.c"
// #include "parse_info.c"
// #include "parsing_map1.c"
// #include "parsing_map2.c"
// #include "parsing_res.c"
// #include "parsing_rgb.c"
// #include "parsing_texture.c"
// #include "raycasting.c"
// #include "raycasting2.c"
// #include "raycasting3.c"
// #include "sprite.c"
// #include "sprite2.c"
// #include "utils.c"


void	want_save(t_cub *cub, int ac, char *av2)
{
	if (ac == 3)
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

void	get_lines2(t_cub *cub, t_info *infos, char *av1)
{
	int fd;
	int ret;
	int x;
	int i;
	char *str;

	i = 0;
	x = 0;
	ret = 0;
	fd = open(av1, O_RDONLY);
	if (!(cub->parse.map = (char **)malloc(sizeof(char *) * (cub->parse.nbline + 1))))
		ft_error("Allocated map fail");
	while (++x < cub->parse.nbline + 1)
		cub->parse.map[x] = 0;
	while ((ret = get_next_line(fd, &str)) > 0 && i < cub->parse.nbline)
	{
		if (find_in(str[0], " 012") && ++i)
			parsing_map(cub, str);
		free(str);
	}
}


void	get_lines(t_cub *cub, t_info *infos, char *av1)
{
	int		ret;
	int		i;
	int		x;
	int		fd;
	char	*str;

	fd = open(av1, O_RDONLY);
	ret = 0;
	i = 0;
	x = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		parsing_informations(cub, infos, str);
		free(str);
	}
	close(fd);
	ret = 0;
	fd = open(av1, O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0 && cub->parse.flag != 2)
	{
		parsing_line(cub, str);
		free(str);
	}
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		parsing_line(cub, str);
		free(str);
	}
	close(fd);
	get_lines2(cub, infos, av1);
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
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
