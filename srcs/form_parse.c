/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:00:36 by tsarafia          #+#    #+#             */
/*   Updated: 2020/06/02 12:01:45 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		form_parse(char *av1)
{
	int		fd;
	char	*str;
	int		ret;

	len = 0;
	fd = open(av1, O_RDWR);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		free(str);
	}
	write(fd, "\n\n\n", 3);
	close(fd);
}
