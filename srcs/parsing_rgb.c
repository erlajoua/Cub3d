/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:31:50 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/09 18:28:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	parsing_floor(t_cub *cub, char *line)
{
	line++;
	if (secure_rgb(cub, line) == 0)
		return (0);
	if (!(cub->parse.floor_rgb[0] = ft_atoi(line)) &&
	cub->parse.floor_rgb[0] != 0)
		return (0);
	line = rgb_parser(cub, line);
	cub->parse.floor_rgb[1] = ft_atoi(line);
	line = rgb_parser(cub, line);
	cub->parse.floor_rgb[2] = ft_atoi(line);
	if ((cub->parse.floor_rgb[0] < 0 || cub->parse.floor_rgb[0] > 255)
		|| (cub->parse.floor_rgb[1] < 0 || cub->parse.floor_rgb[1] > 255)
		|| (cub->parse.floor_rgb[2] < 0 || cub->parse.floor_rgb[2] > 255))
		return (0);
	cub->floor++;
	return (1);
}

int	parsing_ceiling(t_cub *cub, char *line)
{
	line++;
	if (secure_rgb(cub, line) == 0)
		return (0);
	if (!(cub->parse.ceiling_rgb[0] = ft_atoi(line))
	&& cub->parse.ceiling_rgb[0] != 0)
		return (0);
	line = rgb_parser(cub, line);
	cub->parse.ceiling_rgb[1] = ft_atoi(line);
	line = rgb_parser(cub, line);
	cub->parse.ceiling_rgb[2] = ft_atoi(line);
	if ((cub->parse.ceiling_rgb[0] < 0 || cub->parse.ceiling_rgb[0] > 255)
		|| (cub->parse.ceiling_rgb[1] < 0 || cub->parse.ceiling_rgb[1] > 255)
		|| (cub->parse.ceiling_rgb[2] < 0 || cub->parse.ceiling_rgb[2] > 255))
		return (0);
	cub->ceil++;
	return (1);
}
