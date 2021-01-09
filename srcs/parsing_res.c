/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:31:47 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/09 18:17:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		secure_res(char *line)
{
	int i;
	int nb;

	i = 1;
	nb = 0;
	while (line[i])
	{
		if (line[i] && line[i] != ' ' && !ft_isdigit(line[i]))
			ft_error("Invalid character for resolution");
		if (line[i] && ft_isdigit(line[i]))
		{
			nb++;
			while (line[i] && ft_isdigit(line[i]))
				i++;
			i--;
		}
		i++;
	}
	if (nb != 2)
		return (0);
	return (1);
}

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
	cub->start_y = 0;
	cub->ind_y = 0;
	while (!ft_isdigit(line[cub->ind_y]))
		cub->ind_y++;
	while (ft_isdigit(line[cub->ind_y]))
		cub->ind_y++;
	while (!ft_isdigit(line[cub->ind_y]) && line[cub->ind_y] != '-')
		cub->ind_y++;
	while (ft_isdigit(line[cub->ind_y]) || line[cub->ind_y] == '-')
	{
		cub->start_y++;
		cub->ind_y++;
	}
	if (!(cub->parse.res_y = malloc(sizeof(char) * cub->start_y + 1)))
		ft_error("malloc fail");
	cub->ind_y -= cub->start_y;
	cub->start_y = 0;
	while (ft_isdigit(line[cub->ind_y]) || line[cub->ind_y] == '-')
	{
		cub->parse.res_y[cub->start_y] = line[cub->ind_y];
		cub->start_y++;
		cub->ind_y++;
	}
	cub->parse.res_y[cub->start_y] = '\0';
}

int		parsing_res(t_cub *cub, t_info *infos, char *line)
{
	cub->res = secure_res(line);
	if (cub->res == 1)
	{
		parsing_res_x(cub, line);
		parsing_res_y(cub, line);
		infos->resx = ft_atoi(cub->parse.res_x);
		infos->resy = ft_atoi(cub->parse.res_y);
		free(cub->parse.res_x);
		free(cub->parse.res_y);
	}
	return (1);
}
