/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:17:16 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/19 15:22:16 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	counter1;
	unsigned int	counter2;
	char			*haystackcop;

	haystackcop = (char *)haystack;
	if (needle[0] == '\0')
		return (haystackcop);
	counter1 = 0;
	counter2 = 0;
	while (haystack[counter1] != '\0' && counter1 < len)
	{
		counter2 = 0;
		while (haystack[counter1 + counter2] ==
				needle[counter2] && counter1 + counter2 < len)
		{
			counter2++;
			if (needle[counter2] == '\0')
				return (&haystackcop[counter1]);
		}
		counter1++;
	}
	return (0);
}
