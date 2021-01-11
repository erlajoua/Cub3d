/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:34:17 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/11 08:57:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		parsing_north(t_cub *cub, char *line)
{
	int fd;

	line += 2;
	while (*line != '.' && *line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	if (!(delete_sp(line)))
		return (0);
	if (!(cub->parse.north = ft_strdup(line)))
		ft_error("Malloc failed");
	cub->no++;
	if (!(check_ext(cub->parse.north, ".xpm")))
		return (0);
	if (cub->parse.north[0] == '\0')
		return (0);
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

int		parsing_west(t_cub *cub, char *line)
{
	int fd;

	line += 2;
	while (*line != '.' && *line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	if (!(delete_sp(line)))
		return (0);
	if (!(cub->parse.west = ft_strdup(line)))
		ft_error("Malloc failed");
	cub->we++;
	if (!(check_ext(cub->parse.west, ".xpm")))
		return (0);
	if (cub->parse.west[0] == '\0')
		return (0);
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

int		parsing_east(t_cub *cub, char *line)
{
	int fd;

	line += 2;
	while (*line != '.' && *line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	if (!(delete_sp(line)))
		return (0);
	if (!(cub->parse.east = ft_strdup(line)))
		ft_error("Malloc failed");
	cub->ea++;
	if (!(check_ext(cub->parse.east, ".xpm")))
		return (0);
	if (cub->parse.east[0] == '\0')
		return (0);
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

int		parsing_south(t_cub *cub, char *line)
{
	int fd;

	line += 2;
	while (*line != '.' && *line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	if (!(delete_sp(line)))
		return (0);
	if (!(cub->parse.south = ft_strdup(line)))
		ft_error("Malloc failed");
	cub->so++;
	if (!(check_ext(cub->parse.south, ".xpm")))
		return (0);
	if (cub->parse.south[0] == '\0')
		return (0);
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}

int		parsing_sprite(t_cub *cub, char *line)
{
	int fd;

	line += 1;
	while (*line != '.' && *line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	if (!(delete_sp(line)))
		return (0);
	if (!(cub->parse.sprite = ft_strdup(line)))
		ft_error("Malloc failed");
	cub->spr++;
	if (!(check_ext(cub->parse.sprite, ".xpm")))
		return (0);
	if (cub->parse.sprite[0] == '\0')
		return (0);
	fd = open(cub->parse.sprite, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	return (1);
}
