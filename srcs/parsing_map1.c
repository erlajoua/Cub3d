/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:57:25 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/11 10:57:26 by erlajoua         ###   ########.fr       */
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

int		parsing_map(t_cub *cub, char *line)
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
			return (0);
		if (!find_in(line[i], " 012NSEW"))
			return (0);
		i++;
	}
	cub->parse.map[cub->parse.i++] = ft_strdup(line);
	return (1);
}

int		check_map(t_cub *cub)
{
	int y;

	y = 1;
	if (cub->parse.side == '0')
		return (0);
	if (!(first_line_check(cub)))
		return (0);
	while (y < cub->parse.nbline - 1)
	{
		if (!(line_check(cub, y)))
			return (0);
		y++;
	}
	if (!(last_line_check(cub)))
		return (0);
	return (1);
}
