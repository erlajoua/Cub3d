/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:45:50 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/20 13:35:19 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_free(char **tab, int i)
{
	int j;

	j = 0;
	tab[i] = NULL;
	while (tab[j] != NULL)
	{
		free(tab[j]);
		j++;
	}
	free(tab[j]);
	free(tab);
	return (NULL);
}

static	int		is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static	int		count_word(char *str, char charset)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

static	char	*ft_strcpyl(char *str, char charset)
{
	char	*tab;
	int		i;

	i = 0;
	while (*str && !is_charset(*str, charset))
	{
		i++;
		str++;
	}
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
		str--;
	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = count_word((char*)s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && is_charset(*s, c))
			s++;
		if (*s && !is_charset(*s, c))
		{
			if (!(tab[i] = ft_strcpyl((char*)s, c)))
				return (ft_free(tab, i));
			i++;
			while (*s && !is_charset(*s, c))
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
