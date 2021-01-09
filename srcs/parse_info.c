/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 00:37:37 by tsarafia          #+#    #+#             */
/*   Updated: 2020/06/02 12:11:40 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	parse_info(t_cub *cub, t_info *infos, char *line)
{
	if (line[0] == 'R')
		parsing_res(cub, infos, line);
	else if (line[0] == 'N' && line[1] == 'O')
		parsing_north(cub, line);
	else if (line[0] == 'S' && line[1] == 'O')
		parsing_south(cub, line);
	else if (line[0] == 'W' && line[1] == 'E')
		parsing_west(cub, line);
	else if (line[0] == 'E' && line[1] == 'A')
		parsing_east(cub, line);
	else if (line[0] == 'S')
		parsing_sprite(cub, line);
	else if (line[0] == 'F')
		parsing_floor(cub, line);
	else if (line[0] == 'C')
		parsing_ceiling(cub, line);
	else if (line[0] && line[0] != 'R' && line[0] != 'N' && line[0] != 'S'
	&& line[0] != 'W' && line[0] != 'E' && line[0] != 'F' && line[0] != 'C'
	&& line[0] != '\n' && line[0] != '1' && line[0] != '0' && line[0] != '2'
	&& line[0] != ' ')
		ft_error("Character invalid");
}

int		parsing_line(t_cub *cub, char *str)
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
