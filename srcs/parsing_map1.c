/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 00:37:37 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/26 11:42:52 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	fill_sp(t_cub *cub)
{
	int		i;
	int		j;
	int		len;
	char	*s;

	len = 0;
	j = -1;
	while (++j < cub->parse.nbline)
	{
		i = -1;
		len = ft_strlen(cub->parse.map[j]);
		s = ft_strdup(cub->parse.map[j]);
		free(cub->parse.map[j]);
		if (!(cub->parse.map[j] = (char *)malloc(sizeof(char) *
						cub->parse.strlen + 1)))
			return ((void)NULL);
		while (++i < cub->parse.strlen)
			cub->parse.map[j][i] = ' ';
		cub->parse.map[j][i] = '\0';
		i = -1;
		while (++i < len)
			cub->parse.map[j][i] = s[i];
		free(s);
	}
}

int		find_in(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	parsing_map(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (cub->parse.side == '0')
		{
			if (line[i] == 'N' || line[i] == 'S'
					|| line[i] == 'E' || line[i] == 'W')
				cub->parse.side = line[i];
		}
		else if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
			ft_error("Map invalid : Spawn's number > 1\n");
		if (!find_in(line[i], " 012NSEW"))
			ft_error("Map invalid : Invalid character in map content...\n");
		i++;
	}
	cub->parse.map[cub->parse.i++] = ft_strdup(line);
}

int		check_map(t_cub *cub)
{
	int y;

	y = 1;
	if (cub->parse.side == '0')
		ft_error("Map invalid : No side found...\n");
	first_line_check(cub);
	while (y < cub->parse.nbline - 1)
	{
		line_check(cub, y);
		y++;
	}
	last_line_check(cub);
	return (0);
}
