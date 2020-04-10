/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:17:45 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/19 15:10:45 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *dest;

	dest = (0);
	while (*s)
	{
		if (*s == c)
			dest = (char*)s;
		++s;
	}
	if (dest)
		return (dest);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
