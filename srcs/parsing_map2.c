/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:31:40 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/10 13:19:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		last_checkaround(t_cub *cub, int i, int j, char *s)
{
	if (find_in(cub->parse.map[j][i - 1], s)
			&& find_in(cub->parse.map[j][i + 1], s)
			&& find_in(cub->parse.map[j - 1][i], s)
			&& find_in(cub->parse.map[j + 1][i], s))
		return (1);
	return (0);
}

int		line_check(t_cub *cub, int j)
{
	int i;

	i = 0;
	while (cub->parse.map[j][i])
	{
		if (i == 0 && find_in(cub->parse.map[j][0], " 1") == 0)
			return (0);
		if (cub->parse.map[j][i] == ' ')
			if (!check_around(cub, j, i, " 1"))
				return (0);
		if (cub->parse.map[j][i] == '1')
			if (!check_around(cub, j, i, " 012NSEW"))
			{
				return (0);
			}
		if ((cub->parse.map[j][i] == '0') || (cub->parse.map[j][i] == '2')
				|| ((cub->parse.map[j][i] == 'N' || cub->parse.map[j][i] == 'S'
				|| cub->parse.map[j][i] == 'E' || cub->parse.map[j][i] == 'W')))
		{
			if (!check_around(cub, j, i, "012NSEW"))
				return (0);
		}
		i++;
	}
	return (1);
}

int		first_line_check(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->parse.map[0][i])
	{
		if (cub->parse.map[0][i] == '1' || cub->parse.map[0][i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		last_line_check(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->parse.map[cub->parse.nbline - 1][i])
	{
		if (cub->parse.map[cub->parse.nbline - 1][i] == '1'
				|| cub->parse.map[cub->parse.nbline - 1][i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		check_around(t_cub *cub, int j, int i, char *s)
{
	if (cub->parse.map[j][i] == cub->parse.side)
	{
		cub->parse.pos[0] = j;
		cub->parse.pos[1] = i;
	}
	if (i == 0)
	{
		if (find_in(cub->parse.map[j][i + 1], s)
				&& find_in(cub->parse.map[j - 1][i], s)
				&& find_in(cub->parse.map[j + 1][i], s))
			return (1);
	}
	if (i == cub->parse.strlen - 1)
	{
		if (find_in(cub->parse.map[j][i - 1], s)
				&& find_in(cub->parse.map[j - 1][i], s)
				&& find_in(cub->parse.map[j + 1][i], s))
			return (1);
	}
	else
	{
		if (last_checkaround(cub, i, j, s) == 1)
			return (1);
	}
	return (0);
}
