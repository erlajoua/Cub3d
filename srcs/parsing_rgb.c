/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:19:28 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:19:31 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	parsing_floor(t_cub *cub, char *line)
{
	line++;
	cub->parse.floor_rgb[0] = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.floor_rgb[1] = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.floor_rgb[2] = ft_atoi(line);
	return (1);
}

int	parsing_ceiling(t_cub *cub, char *line)
{
	line++;
	cub->parse.ceiling_rgb[0] = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.ceiling_rgb[1] = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	cub->parse.ceiling_rgb[2] = ft_atoi(line);
	return (1);
}
