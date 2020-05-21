/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 00:37:37 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:14:39 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	parsing_informations(t_cub *cub, t_info *infos, char *line)
{
	if (line[0] == 'R')
		return (parsing_res(cub, infos, line));
	else if (line[0] == 'N' && line[1] == 'O')
		return (parsing_north(cub, line));
	else if (line[0] == 'S' && line[1] == 'O')
		return (parsing_south(cub, line));
	else if (line[0] == 'W' && line[1] == 'E')
		return (parsing_west(cub, line));
	else if (line[0] == 'E' && line[1] == 'A')
		return (parsing_east(cub, line));
	else if (line[0] == 'S')
		return (parsing_sprite(cub, line));
	else if (line[0] == 'F')
		return (parsing_floor(cub, line));
	else if (line[0] == 'C')
		return (parsing_ceiling(cub, line));
	else
		return (1);
}

int	parsing_line(t_cub *cub, char *str)
{
	int k;
	int j;

	k = 0;
	j = 0;
	if (str[0] == 0 && cub->parse.flag != 0)
		cub->parse.flag = 2;
	if ((str[0] == ' ' || str[0] == '1' || str[0] == '0')
	&& cub->parse.flag != 2)
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
