/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:47:45 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/15 14:50:48 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;
	char	*s;

	s = (char*)src;
	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	if (dstsize == 0)
		return (count);
	i = 0;
	while (s[i] && i < (dstsize - 1))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
