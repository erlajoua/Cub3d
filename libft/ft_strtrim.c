/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:27:26 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/18 18:06:34 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;
	char	*charset;
	char	*trimed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char*)s1;
	charset = (char*)set;
	start = 0;
	while (str[start] && ft_strchr(charset, str[start]) != NULL)
		start++;
	len = ft_strlen(&str[start]);
	if (len != 0)
		while (str[start + len - 1]
				&& ft_strchr(charset, str[start + len - 1]) != NULL)
			len--;
	if ((trimed = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	trimed = ft_strncpy(trimed, &str[start], len);
	trimed[len] = '\0';
	return (trimed);
}
