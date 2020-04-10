#include "cub.h"

void	show_map(t_cub cub)
{
	int x;

	x = 0;
	while(x < cub.parse.nbline)
	{
		printf("%d - ", x + 1);
		printf("%s\n",cub.parse.map[x]);
		x++;
	}
}

int		parsing_map(t_cub *cub, char *line)
{
	int size_map;
	cub->parse.map[cub->parse.i++] = ft_strdup(line);
	return 1;
}

void	fill_zero(t_cub *cub)
{
	int i;
	int j;
	int len;
	char *s;
	
	len = 0;
	i = 0;
	j = 0;
	while(j < cub->parse.nbline)
	{
		i = 0;
		len = ft_strlen(cub->parse.map[j]);
		s = ft_strdup(cub->parse.map[j]);
		cub->parse.map[j] = (char *)malloc(sizeof(char) * cub->parse.strlen + 1);
		if(!cub->parse.map[j])
			return((void)NULL);
		while(i < cub->parse.strlen)
		{
			cub->parse.map[j][i] = ' ';
			i++;
		}
		cub->parse.map[j][i] = '\0';
		i = 0;
		while(i < len)
		{
			cub->parse.map[j][i] = s[i];
			i++;
		}
		j++;
	}
	//show_map(*cub);
	//printf("\n");
}

int	find_in(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int	check_two(t_cub cub, int i, int j)
{
	char *s;

	s = ft_strdup("012");
	if ((find_in(cub.parse.map[j][i - 1], s) == 1)
		&& (find_in(cub.parse.map[j][i + 1], s) == 1)
		&& (find_in(cub.parse.map[j - 1][i], s) == 1)
		&& (find_in(cub.parse.map[j + 1][i], s) == 1))
	{
		return 1;
	}
	else
		return 0;
}

int check_zr(t_cub cub, int i, int j)
{
	char *s;

	//printf("\nCHECKZR Values : i , j : %d , %d\n", i, j);
	s = ft_strdup("012");
	if(i == 0)
	{
		if ((find_in(cub.parse.map[j][i + 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	if(i == cub.parse.strlen - 1)
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1)
			&& (find_in(cub.parse.map[j][i + 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
}

int check_sp(t_cub cub, int i, int j)
{
	char *s;

	//printf("\nCHECKSPACE : Values : i , j : %d , %d\n", i, j);
	s = ft_strdup("1 ");
	if(i == 0)
	{
		if ((find_in(cub.parse.map[j][i + 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	if(i == cub.parse.strlen - 1)
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1)
			&& (find_in(cub.parse.map[j][i + 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	
}

int check_one(t_cub cub, int i, int j)
{
	char *s;

	s = ft_strdup(" 012");
	if(i == 0)
	{
		if ((find_in(cub.parse.map[j][i + 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	if(i == cub.parse.strlen - 1)
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1)
			&& (find_in(cub.parse.map[j][i + 1], s) == 1)
			&& (find_in(cub.parse.map[j - 1][i], s) == 1)
			&& (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	
}

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
void	first_line_check(t_cub cub) //carré
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
void	last_line_check(t_cub cub) //carré
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

int check_map(t_cub cub)
{
	int x;
	int y;
	int i;

	y = 1;
	i = 0;
	first_line_check(cub);
	while(y < cub.parse.nbline - 1)
	{
		//printf("Test line_check de y : %d\n",y);
		line_check(cub, y);
		y++;
	}
	last_line_check(cub);
	return 0;
}

