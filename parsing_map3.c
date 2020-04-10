#include "cub.h"

void	line_check(t_cub cub, int j)
{
	int i;

	i = 0;
	while(cub.parse.map[j][i])
	{
		char *s;

		s = ft_strdup(" 1");
		if(i == 0 && find_in(cub.parse.map[j][0], s) == 0)
		{
			ft_error("Mauvais debut de chaine\n");
		}
		if(cub.parse.map[j][i] == ' ')
		{
			if(!check_sp(cub, i, j))
			{
				ft_error("Map Error : Check_Space\n");
			}
		}
		if(cub.parse.map[j][i] == '1')
		{
			if(!check_one(cub, i, j))
			{
				ft_error("Map Error : Check_One\n");
			}
		}
		if(cub.parse.map[j][i] == '0')
		{
			if(!check_zr(cub, i, j))
			{
				ft_error("Map Error : Check_Zr\n");
			}
		}
		if(cub.parse.map[j][i] == '2')
		{
			if(!check_two(cub, i, j))
				ft_error("Map Error : Check_Two\n");
		}
		i++;
	}
}

void	first_line_check(t_cub cub)
{
	int i;

	i = 0;
	while (cub.parse.map[0][i])
	{
		if (cub.parse.map[0][i] == '1' || cub.parse.map[0][i] == ' ')
		{
			i++;
		}
		else
			ft_error("First line ne contient pas que des espaces ou des 1\n");
	}
}

void	last_line_check(t_cub cub)
{
	int i;

	i = 0;
	while (cub.parse.map[cub.parse.nbline-1][i])
	{
		if (cub.parse.map[cub.parse.nbline-1][i] == '1' || cub.parse.map[cub.parse.nbline-1][i] == ' ')
		{
			i++;
		}
		else
		{
			ft_error("Last line ne contient pas que des espaces ou des 1\n");
		}
	}
}