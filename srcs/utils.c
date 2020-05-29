/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <thomassarafian@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:27:49 by tsarafia          #+#    #+#             */
/*   Updated: 2020/05/22 01:27:49 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		check_ext(char *s, char *ext)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(s);
	if (l >= 5)
	{
		if (s[l - 1] == ext[3] && s[l - 2] == ext[2] && s[l - 3] == ext[1]
			&& s[l - 4] == ext[0])
			return (1);
		else
			ft_error("Extension not working");
	}
	ft_error("Name map invalid");
}

void	ft_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*rgb_parser(t_cub *cub, char *line)
{
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	return (line);
}

void	init_val_spr(t_info *infos, t_cub *cub)
{
	int i;

	i = 0;
	while (i < infos->spr_nb)
	{
		infos->sprite[i].first = 0;
		infos->sprite[i].second = 0;
		infos->sprite[i].x = 0;
		infos->sprite[i].y = 0;
		infos->sprite[i].txt = 0;
		i++;
	}
}
