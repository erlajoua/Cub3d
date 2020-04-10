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

//                11111111111111111111111111111
//                1000000000110000000000001
//                1011000001110000002000001
//                1111111 111111111111111111
//                1111111111111111111111111
//                1001000000000000000000001
//                111111111011000001110000000000001
// 100000000011000001110111111111111
// 11110111111111011100000010001
// 11110111111111011101010010001
// 11000000110101011100000010001
// 10002000000000001100000010001
// 10000000000000001101010010001
// 11000001110101011111011110N0111
// 11110111    1110101 101111010001
// 11111111    1111111 111111111111
// 11110111    1110101 101111010001
// 11111111    1111111 111111111111
// 11110111 1110101 101111010001
// 11111111 1111111 111111111111

// 1111111
// 1111  1
// 11111 1
// 1110111
// 1000001
// 1111111

// 1 : entoure de 1 de 0 et d'esapce
// ' ' : entoure que de 1 et de lui meme
// 0 : entoure de 0 et de 1


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
