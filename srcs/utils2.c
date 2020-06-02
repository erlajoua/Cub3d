/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:02:48 by tsarafia          #+#    #+#             */
/*   Updated: 2020/06/02 12:07:02 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	secure_info(t_cub *cub)
{
	if (cub->res != 1 || cub->no != 1 || cub->so != 1 || cub->ea != 1
	|| cub->we != 1 || cub->spr != 1 || cub->ceil != 1 || cub->floor != 1)
		ft_error("Missing character or double character");
}

void	check_rgb_char(t_cub *cub, char *line)
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
			ft_error("Invalid character in rgb");
		cub->rgb_i++;
	}
	if (cub->sep != 2 || cub->nb != 3)
		ft_error("Invalid rgb format");
}

void	secure_rgb(t_cub *cub, char *line)
{
	int j;

	j = 0;
	check_rgb_char(cub, line);
	cub->rgb_i = 0;
	while (line[cub->rgb_i] && j < 3)
	{
		if (line[cub->rgb_i] && line[cub->rgb_i] == ' ' && j < 3)
			while (line[cub->rgb_i] && line[cub->rgb_i] == ' ')
				cub->rgb_i++;
		if (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]) && j < 3)
			while (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]))
				cub->rgb_i++;
		else
			ft_error("Format rgb invalid");
		if (line[cub->rgb_i] && line[cub->rgb_i] == ' ' && j < 2)
			while (line[cub->rgb_i] && line[cub->rgb_i] == ' ')
				cub->rgb_i++;
		if (line[cub->rgb_i] && line[cub->rgb_i] == ',' && j < 2)
			cub->rgb_i++;
		else if (line[cub->rgb_i] && line[cub->rgb_i] != ',' && j < 2)
			ft_error("Format rgb invalid");
		j++;
	}
}

void	delete_sp(char *str)
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
		if (j > 0)
			str[i] = '\0';
	}
}
