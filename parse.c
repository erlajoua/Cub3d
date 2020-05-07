#include "cub.h"
#include "parsing_map1.c"
#include "parsing_map2.c"
#include "parsing_res.c"
#include "parsing_rgb.c"
#include "parsing_texture.c"
#include "parse_info.c"
#include "new_ray2.c"

void ft_start(t_cub *cub)
{
	cub->parse.i = 0;
	cub->parse.strlen = 0;
	cub->parse.nbline = 0;
	cub->parse.side = '0';
	cub->parse.pos[0] = 0;
	cub->parse.pos[1] = 0;
	cub->parse.flag = 0;
}

void ft_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(0);
}

int main(int ac, char **av)
{
	char *line;
	int fd;
	int rdbytes;
	int ret;
	int i;
	int j;
	char *str;
	char *another;

	ret = 0;
	i = 0;
	j = 0;
	t_cub cub;
	ft_start(&cub);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		parsing_informations(&cub, str);
	}
	close(fd);

	ret = 0;
	fd = open(av[1], O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &str)) > 0 && cub.parse.flag != 2)
	{
		parsing_line(&cub, str);
	}
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		parsing_line(&cub, str);
	}
	close(fd);
	ret = 0;
	fd = open(av[1], O_RDONLY);
	i = 0;
	cub.parse.map = (char **)malloc(sizeof(char *) * cub.parse.nbline + 1);
	while ((ret = get_next_line(fd, &str)) > 0 && i < cub.parse.nbline)
	{
		if (find_in(str[0], " 012"))
		{
			parsing_map(&cub, str);
			i++;
		}
	}
	// printf("(coucou)\n");
	fill_sp(&cub);
	// printf("(coucou)\n");
	check_map(&cub);
	show_parsed(&cub);
	printf("Map valide, affichage...!\n\n");
	show_map(&cub);
	printf("\n");

	t_mlx mlx;
	t_info infos;
	void *params[3];
	mlx.mlx_ptr = mlx_init();
	infos.RESX = ft_atoi(cub.parse.res_x);
	infos.RESY = ft_atoi(cub.parse.res_y);
	/**/
	mlx.win = mlx_new_window(mlx.mlx_ptr, infos.RESX, infos.RESY, "Cub3d");
	params[0] = (void *)&infos;
	params[1] = (void *)&mlx;
	params[2] = (void *)&cub;
	raycasting(&mlx, &infos, &cub);
	mlx_hook(mlx.win, 2, (1L << 0), keypressed, (void *)params);
	mlx_loop(mlx.mlx_ptr);
	return 0;
}
