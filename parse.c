#include "cub.h"
#include "parsing_res.c"
#include "parsing_rgb.c"
#include "parsing_texture.c"
#include "parsing_map1.c"
#include "parsing_map2.c"

void ft_start(t_cub *cub)
{
	cub->parse.i = 0;
	cub->parse.strlen = 0;
	cub->parse.nbline = 0;
	cub->parse.side = '0';
	cub->parse.pos[0] = 0;
	cub->parse.pos[1] = 0;
}

void ft_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(0);
}

int parsing_line(t_cub *cub, char *str)
{
	int i;

	i = 0;
	if ((str[0] == ' ' || str[0] == '1' || str[0] == '0'))
	{
		cub->parse.nbline++;
		while (str[i])
			i++;
		if (cub->parse.strlen == 0)
			cub->parse.strlen = i;
		if (cub->parse.strlen && i > cub->parse.strlen)
			cub->parse.strlen = i;
	}
	return 1;
}

int parsing(t_cub *cub, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'R')
		return parsing_res(cub, line);
	else if (line[0] == 'N' && line[1] == 'O')
		return parsing_north(cub, line);
	else if (line[0] == 'S' && line[1] == 'O')
		return parsing_south(cub, line);
	else if (line[0] == 'W' && line[1] == 'E')
		return parsing_west(cub, line);
	else if (line[0] == 'E' && line[1] == 'A')
		return parsing_east(cub, line);
	else if (line[0] == 'S')
		return parsing_south(cub, line);
	else if (line[0] == 'F')
		return parsing_floor(cub, line);
	else if (line[0] == 'C')
		return parsing_ceiling(cub, line);
	else if ((line[0] == ' ' || line[0] == '1' || line[0] == '0' || line[0] == '\n')) //&& (!ft_strrchr(line, 'R') && !ft_strrchr(line, 'C') && !ft_strrchr(line, 'F')))
		return parsing_map(cub, line);
	return 1;
}

//parsing ce sera toujours le meme ordre mais il peut y avoir des espaces et des \n

int main(int ac, char **av)
{
	char *line;
	int fd;
	int rdbytes;
	int ret;
	int i;
	char *str;

	fd = open(av[1], O_RDONLY);
	ret = 0;
	i = 0;
	t_cub cub;
	ft_start(&cub);
	while ((ret = get_next_line(fd, &str)) > 0)
		parsing_line(&cub, str);
	close(fd);
	ret = 0;
	fd = open(av[1], O_RDONLY);
	cub.parse.map = (char **)malloc(sizeof(char *) * cub.parse.nbline + 1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parsing(&cub, line);
	}
	fill_sp(&cub);
	check_map(&cub);
	printf("Map valide!\n");
	printf("Le joueur commencera en directon du : %c\n\n",cub.parse.side);

	// printf("FINAL cub.parse.pos[0] = %d - cub.parse.pos[1] = %d\n", cub.parse.pos[0], cub.parse.pos[1]);

	show_map(&cub);


	// printf("\nres_x : |%s| res_y : |%s| south : |%s| north : |%s| east : |%s| weast |%s|\n", cub.parse.res_x, cub.parse.res_y, cub.parse.south, cub.parse.north, cub.parse.east, cub.parse.west);
	// printf("FLOOR | R : %d - G : %d - B : %d\n", cub.parse.floor_rgb[0], cub.parse.floor_rgb[1], cub.parse.floor_rgb[2]);
	// printf("CEILING | R : %d - G : %d - B : %d\n", cub.parse.ceiling_rgb[0], cub.parse.ceiling_rgb[1], cub.parse.ceiling_rgb[2]);
	// printf(" -> %d\n", cub.parse.strlen);
	// printf(" -> %d\n", cub.parse.nbline);

	// system("leaks a.out");
	return 0;
}
