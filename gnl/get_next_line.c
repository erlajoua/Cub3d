/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:56:39 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/09 12:56:40 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_manage_rest(t_gnl *p, char **line, char **buffer)
{
	char	*rest;
	char	*subline;
	int		empty_rest;

	if ((rest = ft_getrest(*buffer, &empty_rest)) == NULL && empty_rest == 0)
		return (-1);
	if (empty_rest == 1)
	{
		if ((*line = ft_strjjoin(*line, *buffer)) == NULL)
			return (-1);
		ft_bzero(*buffer, BUFFER_SIZE + 1);
		return (1);
	}
	else
	{
		if ((subline = ft_getline(*buffer)) == NULL)
			return (-1);
		if ((*line = ft_strjjoin(*line, subline)) == NULL)
			return (-1);
		p->rest = rest;
		free(subline);
		return (0);
	}
}

static int	ft_rest(t_gnl *p, char **buffer, int fd, char **line)
{
	int ret;

	if (p->rest)
	{
		*buffer = ft_strcpy(*buffer, p->rest);
		free(p->rest);
		p->rest = NULL;
	}
	else
	{
		p->byte_nb = read(fd, *buffer, BUFFER_SIZE);
		if (p->byte_nb <= 0)
			return (p->byte_nb == 0 ? 0 : -1);
	}
	ret = ft_manage_rest(p, line, buffer);
	if (ret == 0)
		return (2);
	if (ret == -1)
		return (-1);
	return (1);
}

static int	ft_read(int fd, t_gnl *p, char **line)
{
	char	*buffer;
	int		ret;

	ret = 0;
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!(*line = malloc(sizeof(char) * 1)))
	{
		free(buffer);
		return (-1);
	}
	*line[0] = '\0';
	while (ret != 2)
	{
		ret = ft_rest(p, &buffer, fd, line);
		if (ret <= 0)
		{
			free(buffer);
			return (ret);
		}
	}
	free(buffer);
	return (p->byte_nb > 0 || p->rest ? 1 : 0);
}

int			get_next_line(int fd, char **line)
{
	static t_gnl	p;
	int				ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	ret = ft_read(fd, &p, line);
	return (ret);
}
