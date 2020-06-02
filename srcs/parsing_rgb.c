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
	secure_rgb(cub, line);
	if (!(cub->parse.floor_rgb[0] = ft_atoi(line)) &&
	cub->parse.floor_rgb[0] != 0)
		ft_error("Invalid rgb format");
	line = rgb_parser(cub, line);
	cub->parse.floor_rgb[1] = ft_atoi(line);
	line = rgb_parser(cub, line);
	cub->parse.floor_rgb[2] = ft_atoi(line);
	if ((cub->parse.floor_rgb[0] < 0 || cub->parse.floor_rgb[0] > 255)
		|| (cub->parse.floor_rgb[1] < 0 || cub->parse.floor_rgb[1] > 255)
		|| (cub->parse.floor_rgb[2] < 0 || cub->parse.floor_rgb[2] > 255))
		ft_error("Floor value rgb invalid");
	cub->floor++;
	return (1);
}

int	parsing_ceiling(t_cub *cub, char *line)
{
	line++;
	secure_rgb(cub, line);
	if (!(cub->parse.ceiling_rgb[0] = ft_atoi(line))
	&& cub->parse.ceiling_rgb[0] != 0)
		ft_error("Invalid rgb format");
	line = rgb_parser(cub, line);
	cub->parse.ceiling_rgb[1] = ft_atoi(line);
	line = rgb_parser(cub, line);
	cub->parse.ceiling_rgb[2] = ft_atoi(line);
	if ((cub->parse.floor_rgb[0] < 0 || cub->parse.floor_rgb[0] > 255)
		|| (cub->parse.floor_rgb[1] < 0 || cub->parse.floor_rgb[1] > 255)
		|| (cub->parse.floor_rgb[2] < 0 || cub->parse.floor_rgb[2] > 255))
		ft_error("Floor value rgb invalid");
	cub->ceil++;
	return (1);
}
