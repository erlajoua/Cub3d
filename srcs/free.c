/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:06:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 18:24:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	free_rest(char *str, t_cub *cub)
{
	int ret;

	ret = 0;
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
	ret = get_next_line(-1, NULL, 0);
	if (str)
		free(str);
	/*
	if (cub->parsing.
	*/
	write(2, "Error\nParsing infos error", 25);
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
