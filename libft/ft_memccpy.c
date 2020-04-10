/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:52:18 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/15 15:19:18 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char i;
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	i = (unsigned char)c;
	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	while (n > 0)
	{
		if (*ptr_src == i)
		{
			*(ptr_dst++) = *(ptr_src++);
			return (ptr_dst);
		}
		*(ptr_dst++) = *(ptr_src++);
		n--;
	}
	return (NULL);
}
