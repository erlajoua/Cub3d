/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:20:05 by tsarafia          #+#    #+#             */
/*   Updated: 2020/06/02 12:11:13 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		parsing_north(t_cub *cub, char *line)
{
	int fd;

	while (*line != '.' && *line)
		line++;
	delete_sp(line);
	if (!(cub->parse.north = ft_strdup(line)))
		ft_error("parsing fail");
	check_ext(cub->parse.north, ".xpm");
	if (cub->parse.north[0] == '\0')
		ft_error("No north texture");
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("No north texture");
	}
	cub->no++;
	return (1);
}

int		parsing_west(t_cub *cub, char *line)
{
	int fd;

	while (*line != '.' && *line)
		line++;
	delete_sp(line);
	if (!(cub->parse.west = ft_strdup(line)))
		ft_error("parsing fail");
	check_ext(cub->parse.west, ".xpm");
	if (cub->parse.west[0] == '\0')
		ft_error("No west texture");
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("No west texture");
	}
	cub->we++;
	return (1);
}

int		parsing_east(t_cub *cub, char *line)
{
	int fd;

	while (*line != '.' && *line)
		line++;
	delete_sp(line);
	if (!(cub->parse.east = ft_strdup(line)))
		ft_error("parsing fail");
	check_ext(cub->parse.east, ".xpm");
	if (cub->parse.east[0] == '\0')
		ft_error("No east texture");
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("No east texture");
	}
	cub->ea++;
	return (1);
}

int		parsing_south(t_cub *cub, char *line)
{
	int fd;

	while (*line != '.' && *line)
		line++;
	delete_sp(line);
	if (!(cub->parse.south = ft_strdup(line)))
		ft_error("parsing fail");
	check_ext(cub->parse.south, ".xpm");
	if (cub->parse.south[0] == '\0')
		ft_error("No south texture");
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("No south texture");
	}
	cub->so++;
	return (1);
}

int		parsing_sprite(t_cub *cub, char *line)
{
	int fd;

	while (*line != '.' && *line)
		line++;
	delete_sp(line);
	if (!(cub->parse.sprite = ft_strdup(line)))
		ft_error("parsing fail");
	check_ext(cub->parse.sprite, ".xpm");
	if (cub->parse.sprite[0] == '\0')
		ft_error("No sprite texture");
	fd = open(cub->parse.sprite, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error("No sprite texture");
	}
	cub->spr++;
	return (1);
}
