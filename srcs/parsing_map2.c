/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:17:20 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:17:44 by tsarafia         ###   ########.fr       */
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

void	line_check(t_cub *cub, int j)
{
	int i;

	i = 0;
	while (cub->parse.map[j][i])
	{
		if (i == 0 && find_in(cub->parse.map[j][0], " 1") == 0)
			ft_error("Map invalid\n");
		if (cub->parse.map[j][i] == ' ')
			if (!check_around(cub, j, i, " 1"))
				ft_error("Map invalid\n");
		if (cub->parse.map[j][i] == '1')
			if (!check_around(cub, j, i, " 012NSEW"))
			{
				ft_error("Map invalid\n");
			}
		if ((cub->parse.map[j][i] == '0') || (cub->parse.map[j][i] == '2')
				|| ((cub->parse.map[j][i] == 'N' || cub->parse.map[j][i] == 'S'
				|| cub->parse.map[j][i] == 'E' || cub->parse.map[j][i] == 'W')))
		{
			if (!check_around(cub, j, i, "012NSEW"))
				ft_error("Map invalid\n");
		}
		i++;
	}
}

void	first_line_check(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->parse.map[0][i])
	{
		if (cub->parse.map[0][i] == '1' || cub->parse.map[0][i] == ' ')
			i++;
		else
			ft_error("Map invalid\n");
	}
}

void	last_line_check(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->parse.map[cub->parse.nbline - 1][i])
	{
		if (cub->parse.map[cub->parse.nbline - 1][i] == '1'
				|| cub->parse.map[cub->parse.nbline - 1][i] == ' ')
			i++;
		else
			ft_error("Map invalid\n");
	}
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
