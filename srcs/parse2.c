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

void	check_end(char *str)
{
	int i;

	i = 0;
	printf("je recois ca : %s\n",str);
	while(str[i])
	{
		if(!find_in(str[i], " 012NSWE\n"))
			ft_error("bad content below the map\n");
		i++;
	}
}

int		onlyspace(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if(str[i] == '\0')
		return (1);
	return (0);	
}

void	get_lines3(t_cub *cub, t_info *infos, char *av1)
{
	int		ret;
	int		fd;
	char	*str;
	int		x;
	int		i;

	i = 0;
	x = 0;
	ret = 0;
	fd = open(av1, O_RDONLY);
	cub->parse.map = (char **)malloc(sizeof(char *) * (cub->parse.nbline + 1));
	if (!cub->parse.map)
		ft_error("Allocated map fail");
	while (++x < cub->parse.nbline + 1)
		cub->parse.map[x] = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		//printf("recup : %s\n",str);
		if (find_in(str[0], " 012") && ++i)
		{
			if(onlyspace(str))
				ft_error("line contains only spaces\n");
			int k = 0;
			while(str[k] == ' ')
				k++;
			if(!find_in(str[k], "RNSEWFC"))
			{
				// printf("PASSAGE \n");
				parsing_map(cub, str);
			}
		}
		free(str);
	}
	if (find_in(str[0], " 012") && ++i)
	{
		int k = 0;
		while(str[k] == ' ')
			k++;
		if(!find_in(str[k], "RNSEWFC"))
		{
			// printf("Chaine(out) : %s\n",str);
			parsing_map(cub, str);
		}
	}
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
	while ((ret = get_next_line(fd, &str)) > 0 && cub->parse.flag != 2)
	{
		printf("str recup : %s\n",str);
		parsing_line(cub, str);
		free(str);
	}
	parsing_line(cub, str);
	free(str);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		//printf("str recup : %s\n",str);
		check_end(str);
		parsing_line(cub, str);
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
