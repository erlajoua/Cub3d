/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:56:36 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/11 10:56:37 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	free_rest(char *str, t_cub *cub)
{
	int ret;

	ret = 0;
	if (cub->no >= 1)
		free(cub->parse.north);
	if (cub->we >= 1)
		free(cub->parse.west);
	if (cub->so >= 1)
		free(cub->parse.south);
	if (cub->ea >= 1)
		free(cub->parse.east);
	if (cub->spr >= 1)
		free(cub->parse.sprite);
	free(str);
	ret = get_next_line(-1, NULL, 0);
	write(2, "Error\nParsing infos error", 25);
	exit(0);
}

int		free_direction(t_cub *cub)
{
	if (cub->parse.north)
		free(cub->parse.north);
	if (cub->parse.west)
		free(cub->parse.west);
	if (cub->parse.south)
		free(cub->parse.south);
	if (cub->parse.east)
		free(cub->parse.east);
	if (cub->parse.sprite)
		free(cub->parse.sprite);
	return (0);
}

void	free_maperror(char *str, t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->parse.nbline + 1)
	{
		if (cub->parse.map[i])
			free(cub->parse.map[i]);
		i++;
	}
	free(cub->parse.map);
	free_direction(cub);
	if (str)
		free(str);
	get_next_line(-1, NULL, 0);
	write(2, "Error\nMap parsing error", 23);
	exit(0);
}

void	free_map(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->parse.nbline + 1)
	{
		free(cub->parse.map[i]);
		i++;
	}
	free(cub->parse.map);
}
