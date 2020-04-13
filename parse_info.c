#include "cub.h"

void    show_parsed(t_cub *cub)
{
    printf("Résolution :\n\n\tres_x |%s|, res_y |%s|\n",cub->parse.res_x, cub->parse.res_y);
    printf("\nMap :\n\n\tNorth : |%s|\n\tSouth : |%s|\n\tWest  : |%s|\n\tEast  : |%s|\n\tSprite: |%s|\n", cub->parse.north, cub->parse.south, cub->parse.west, cub->parse.east,  cub->parse.sprite);
    printf("\nFloor :\n\n\tR : |%d|\n\tG : |%d|\n\tB : |%d|\n", cub->parse.floor_rgb[0], cub->parse.floor_rgb[1], cub->parse.floor_rgb[2]);
    printf("\nCeiling :\n\n\tR : |%d|\n\tG : |%d|\n\tB : |%d|\n", cub->parse.ceiling_rgb[0], cub->parse.ceiling_rgb[1], cub->parse.ceiling_rgb[2]);
    printf("\nParamètres de la map :\n\n\tNombre de lignes   : |%d|\n\tNombre de char max : |%d|\n\tOrientation spawn  : |%c|\n\tPosition du spawn  : [%d,%d]\n\n", cub->parse.nbline, cub->parse.strlen, cub->parse.side, cub->parse.pos[0], cub->parse.pos[1]);
}

int parsing_informations(t_cub *cub, char *line)
{
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
        return parsing_sprite(cub, line);
    else if (line[0] == 'F')
        return parsing_floor(cub, line);
    else if (line[0] == 'C')
        return parsing_ceiling(cub, line);
    else
        return (1);
}

int parsing_line(t_cub *cub, char *str)
{
	int k;
    int j;

	k = 0;
    j = 0;
    if (str[0] == 0 && cub->parse.flag != 0)
        cub->parse.flag = 2;
	if ((str[0] == ' ' || str[0] == '1' || str[0] == '0') && cub->parse.flag != 2)
	{
        cub->parse.flag = 1;
		cub->parse.nbline++;
		while (str[k])
			k++;
		if (cub->parse.strlen == 0)
			cub->parse.strlen = k;
		if (cub->parse.strlen && k > cub->parse.strlen)
			cub->parse.strlen = k;
        j++;
	}
	return (j);
}
