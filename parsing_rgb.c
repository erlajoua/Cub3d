#include "cub.h"

int		parsing_floor(t_cub *cub, char *line)
{

	line++;
	cub->parse.floor_rgb[0]  = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.floor_rgb[1]  = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.floor_rgb[2]  = ft_atoi(line);
	return 1;
}

int		parsing_ceiling(t_cub *cub, char *line)
{

	line++;
	cub->parse.ceiling_rgb[0]  = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.ceiling_rgb[1]  = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.ceiling_rgb[2]  = ft_atoi(line);
	return 1;
}
