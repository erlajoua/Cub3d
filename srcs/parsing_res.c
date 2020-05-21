/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <tsarafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:26:46 by tsarafia          #+#    #+#             */
/*   Updated: 2020/03/12 16:26:50 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	parsing_res_x(t_cub *cub, char *line)
{
	int start;
	int j;

	start = 0;
	j = 0;
	while (!ft_isdigit(line[j]) && line[j] != '-')
		j++;
	while (ft_isdigit(line[j]) || line[j] == '-')
	{
		j++;
		start++;
	}
	if (!(cub->parse.res_x = malloc(sizeof(char) * start + 1)))
		ft_error("malloc fail");
	j = j - start;
	start = 0;
	while (ft_isdigit(line[j]) || line[j] == '-')
	{
		cub->parse.res_x[start] = line[j];
		j++;
		start++;
	}
	cub->parse.res_x[start] = '\0';
}

void	parsing_res_y(t_cub *cub, char *line)
{
	int start;
	int j;

	start = 0;
	j = 0;
	while (!ft_isdigit(line[j]))
		j++;
	while (ft_isdigit(line[j]))
		j++;
	while (!ft_isdigit(line[j]) && line[j] != '-')
		j++;
	j--;
	while (ft_isdigit(line[j++]))
		start++;
	if (!(cub->parse.res_y = malloc(sizeof(char) * start + 1)))
		ft_error("malloc fail");
	j -= start;
	start = 0;
	while (ft_isdigit(line[j]) || line[j] == '-')
	{
		cub->parse.res_y[start] = line[j];
		start++;
		j++;
	}
	cub->parse.res_y[start] = '\0';
}

int	parsing_res(t_cub *cub, t_info *infos, char *line)
{
	parsing_res_x(cub, line);
	parsing_res_y(cub, line);
	infos->RESX = ft_atoi(cub->parse.res_x);
	infos->RESY = ft_atoi(cub->parse.res_y);
	if (infos->RESX > 2560 || infos->RESX <= 0)
		infos->RESX = 2560;
	if (infos->RESY > 1440 || infos->RESY <= 0)
		infos->RESY = 1440;
	return (1);
}
