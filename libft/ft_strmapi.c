/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:38:35 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/12 11:02:57 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*dest;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char*)s;
	dest = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
