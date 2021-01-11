/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:32:22 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/11 08:57:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	secure_info(t_cub *cub)
{
	if (cub->res != 1 || cub->no != 1 || cub->so != 1 || cub->ea != 1
	|| cub->we != 1 || cub->spr != 1 || cub->ceil != 1 || cub->floor != 1)
		free_rest(NULL, cub);
}

int		check_rgb_char(t_cub *cub, char *line)
{
	cub->rgb_i = 0;
	cub->sep = 0;
	cub->nb = 0;
	while (line[cub->rgb_i])
	{
		if (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]))
		{
			cub->nb++;
			while (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]))
				cub->rgb_i++;
			cub->rgb_i--;
		}
		if (line[cub->rgb_i] && line[cub->rgb_i] == ',')
			cub->sep++;
		if (line[cub->rgb_i] && !ft_isdigit(line[cub->rgb_i])
			&& line[cub->rgb_i] != ' ' && line[cub->rgb_i] != ',')
			return (0);
		cub->rgb_i++;
	}
	if (cub->sep != 2 || cub->nb != 3)
		return (0);
	return (1);
}

int		secure_rgb(t_cub *cub, char *line)
{
	int j;

	j = -1;
	if (check_rgb_char(cub, line) == 0)
		return (0);
	cub->rgb_i = 0;
	while (line[cub->rgb_i] && j++ < 3)
	{
		if (line[cub->rgb_i] && line[cub->rgb_i] == ' ' && j < 3)
			while (line[cub->rgb_i] && line[cub->rgb_i] == ' ')
				cub->rgb_i++;
		if (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]) && j < 3)
			while (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]))
				cub->rgb_i++;
		else
			return (0);
		if (line[cub->rgb_i] && line[cub->rgb_i] == ' ' && j < 2)
			while (line[cub->rgb_i] && line[cub->rgb_i] == ' ')
				cub->rgb_i++;
		if (line[cub->rgb_i] && line[cub->rgb_i] == ',' && j < 2)
			cub->rgb_i++;
		else if (line[cub->rgb_i] && line[cub->rgb_i] != ',' && j < 2)
			return (0);
	}
	return (1);
}

int		delete_sp(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	if (str[i] != '\0')
	{
		j = i;
		while (str[j] == ' ')
			j++;
		if (str[j] != '\0')
			return (0);
		if (j > 0)
			str[i] = '\0';
	}
	return (1);
}
