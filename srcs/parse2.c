/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:31:12 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/10 21:42:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	get_lines3(t_cub *cub, t_info *infos, char *av1)
{
	int		ret;
	int		fd;
	char	*str;
	int		x;
	int		i;

	(void)infos;
	i = 0;
	x = 0;
	ret = 0;
	fd = open(av1, O_RDONLY);
	cub->parse.map = (char **)malloc(sizeof(char *) * (cub->parse.nbline + 1));
	if (!cub->parse.map)
		ft_error("Allocated map fail");
	while (++x < cub->parse.nbline + 1)
		cub->parse.map[x] = 0;
	while ((ret = get_next_line(fd, &str, 1)) > 0 && i < cub->parse.nbline)
	{
		if (find_in(str[0], " 012") && ++i)
			if (!(parsing_map(cub, str)))
				free_maperror(str, cub);
		free(str);
	}
	parsing_map(cub, str);
	free(str);
}

void	get_lines2(t_cub *cub, t_info *infos, char *av1)
{
	int		fd;
	int		ret;
	int		x;
	int		i;
	char	*str;

	i = 0;
	x = 0;
	ret = 0;
	fd = open(av1, O_RDONLY);
	while ((ret = get_next_line(fd, &str, 1)) > 0 && cub->parse.flag != 2)
	{
		parsing_line(cub, str);
		free(str);
	}
	parsing_line(cub, str);
	free(str);
	while ((ret = get_next_line(fd, &str, 1)) > 0)
	{
		parsing_line(cub, str);
		free(str);
	}
	free(str);
	close(fd);
	get_lines3(cub, infos, av1);
}

void	get_lines(t_cub *cub, t_info *infos, char *av1)
{
	int		ret;
	int		i;
	int		x;
	int		fd;
	char	*str;

	ret = 0;
	str = NULL;
	i = 0;
	x = 0;
	fd = open(av1, O_RDONLY);
	if (fd < 0)
		ft_error("file not exist");
	while ((ret = get_next_line(fd, &str, 1)) > 0)
	{
		if (!(parse_info(cub, infos, str)))
			free_rest(str, cub);
		free(str);
	}
	free(str);
	secure_info(cub);
	close(fd);
	get_lines2(cub, infos, av1);
}
