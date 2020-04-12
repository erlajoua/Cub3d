#include "cub.h"

void fill_sp(t_cub *cub)
{
	int i;
	int j;
	int len;
	char *s;

	len = 0;
	j = -1;
	while (++j < cub->parse.nbline)
	{
		i = -1;
		len = ft_strlen(cub->parse.map[j]);
		s = ft_strdup(cub->parse.map[j]);
		cub->parse.map[j] = (char *)malloc(sizeof(char) * cub->parse.strlen + 1);
		if (!cub->parse.map[j])
			return ((void)NULL);
		while (++i < cub->parse.strlen)
			cub->parse.map[j][i] = ' ';
		cub->parse.map[j][i] = '\0';
		i = -1;
		while (++i < len)
			cub->parse.map[j][i] = s[i];
	}
	//show_map(*cub);
}

int find_in(char c, char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void show_map(t_cub *cub)
{
	int x;

	x = 0;
	while (x < cub->parse.nbline)
	{
		printf("%d - ", x + 1);
		printf("%s\n", cub->parse.map[x]);
		x++;
	}
}

int parsing_map(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (cub->parse.side == '0')
		{
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
					cub->parse.side = line[i];
		}
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			ft_error("double side\n");
		if (!find_in(line[i], " 012NSEW"))
			ft_error("invalid character\n\n\n");
		i++;
	}
	cub->parse.map[cub->parse.i++] = ft_strdup(line);
	return (1);
}

int check_map(t_cub *cub)
{
	int y;

	y = 1;
	if(cub->parse.side == '0')
        ft_error("no side found");
	first_line_check(cub);
	while (y < cub->parse.nbline - 1)
	{
		line_check(cub, y);
		y++;
	}
	last_line_check(cub);
	return 0;
}
