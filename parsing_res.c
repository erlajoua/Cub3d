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


#include "cub.h"

void	parsing_res_x(t_cub *cub, char *line)
{
	int start;
	int i;
	int j;

	start = 0;
	i = 0;
	j = 0;
	while (!ft_isdigit(line[j]))
		j++;
	while (ft_isdigit(line[j]))
	{
		j++;
		start++;
	}
	if (!(cub->parse.res_x = malloc(sizeof(char) * start + 1)))
		ft_error("malloc fail");
	j = j - start;
	start = 0;
	while (ft_isdigit(line[j]))
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
	int i;
	int j;

	start = 0;
	i = 0;
	j = 0;
	while (!ft_isdigit(line[j]))
		j++;
	while (ft_isdigit(line[j]))
		j++;
	while (!ft_isdigit(line[j]))
		j++;
	j--;
	while (ft_isdigit(line[j++]))
		start++;
	if (!(cub->parse.res_y = malloc(sizeof(char) * start + 1)))
		ft_error("malloc fail");
	j -= start;
	start = 0;
	while (ft_isdigit(line[j]))
	{
		cub->parse.res_y[start] = line[j];
		start++;
		j++;
	}
	cub->parse.res_y[start] = '\0';
}

int parsing_res(t_cub *cub, char *line)
{

	parsing_res_x(cub, line);
	parsing_res_y(cub, line);

	return (1); //ERROR A CORIGER
}
