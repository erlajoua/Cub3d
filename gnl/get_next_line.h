/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:57:03 by erlajoua          #+#    #+#             */
/*   Updated: 2021/01/09 12:57:03 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2048
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char			*ft_strjjoin(char const *s1, char const *s2);
int				ft_strlen(char *s);
char			*ft_strcpy(char *dest, char *src);
char			*ft_getline(char *str);
char			*ft_getrest(char *str, int *empty_rest);
int				get_next_line(int fd, char **line);
void			ft_bzero(void *s, size_t n);

struct			s_gnl
{
	char	*rest;
	int		byte_nb;
};
typedef	struct s_gnl	t_gnl;

#endif
