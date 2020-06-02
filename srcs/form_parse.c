/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:00:36 by tsarafia          #+#    #+#             */
/*   Updated: 2020/06/02 14:12:36 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void		form_parse2(t_cub *cub, char *av1)
{
	int ret = 0;
	int fd;
	char *str;
	int len = cub->parse.nbline;
	printf("%d\n", len);
	fd = open(av1, O_RDWR);
	while ((ret = get_next_line(fd, &str)) > 0 && len > 3)
	{
		len--;
		free(str);
	}
	write(fd, "\0", 1);
	close(fd);
}

void	form_parse( char *av1)
{
	int		fd;
	char	*str;
	int		ret;
	int		len;

	len = 0;
	fd = open(av1, O_RDWR);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		free(str);
		len++;
	}
	write(fd, "\n\n\n", 3);
	close(fd);
}
