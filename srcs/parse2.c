/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:25:42 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/26 12:25:46 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

char 	*get_lines3bis(t_cub *cub, t_info *infos, char *av1)
{
	char *str;
	int x;
	int fd;
	int ret;
	// int	lenght;

	// lenght = &len;
	ret = 0;
	fd = open(av1, O_RDONLY);
	x = 0;
	while (++x < cub->parse.nbline + 1)
		cub->parse.map[x] = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (find_in(str[0], " 012"))
		{
			if (onlyspace(str))
				ft_error("line contains only spaces\n");
			x = 0;
			while (str[x] == ' ')
				x++;
			if (!(find_in(str[x], "RNSEWFC")) && cub->parse.len > 0)
			{
				parsing_map(cub, str);
				cub->parse.len--;
			}
		}
		free(str);
	}
	return (str);
}

void	check_end(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!find_in(str[i], " 012NSWE\n"))
			ft_error("bad content below the map\n");
		i++;
	}
}

void	get_lines3(t_cub *cub, t_info *infos, char *av1)
{
	int		ret;
	int		fd;
	char	*str;
	int		x;

	x = 0;
	cub->parse.len = cub->parse.nbline;
	ret = 0;
	fd = open(av1, O_RDONLY);
	cub->parse.map = (char **)malloc(sizeof(char *) * (cub->parse.nbline + 1));
	if (!cub->parse.map)
		ft_error("Allocated map fail");
	str = get_lines3bis(cub, infos, av1);
	if (find_in(str[0], " 012"))
	{
		while (str[x] == ' ' && str[x])
			x++;
		if (!(find_in(str[x], "RNSEWFC")) && cub->parse.len > 0)
		{
			parsing_map(cub, str);
			cub->parse.len--;
		}
	}
	free(str);
}

void	get_lines2(t_cub *cub, t_info *infos, char *av1)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 0;
	fd = open(av1, O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0 && cub->parse.flag != 2)
	{
		parsing_line(cub, str);
		free(str);
	}
	parsing_line(cub, str);
	free(str);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		check_end(str);
		free(str);
	}
	check_end(str);
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
	i = 0;
	x = 0;
	fd = open(av1, O_RDONLY);
	if (fd < 0)
		ft_error("file not exist");
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		parse_info(cub, infos, str);
		free(str);
	}
	free(str);
	secure_info(cub);
	close(fd);
	get_lines2(cub, infos, av1);
}
