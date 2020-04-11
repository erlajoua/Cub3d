/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:55:58 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/12 16:44:53 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	i;

	ptr_s = (unsigned char*)s;
	i = (unsigned char)c;
	while (n-- > 0)
	{
		if (*ptr_s == i)
			return (ptr_s);
		(ptr_s++);
	}
	return (NULL);
}
