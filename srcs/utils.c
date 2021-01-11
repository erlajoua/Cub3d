/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:32:26 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/11 08:54:31 by user42           ###   ########.fr       */
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
			return (0);
	}
	return (0);
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
	(void)cub;
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
	(void)cub;
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
