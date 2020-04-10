/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:39:40 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/13 19:40:09 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	elem = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		elem->next = ft_lstnew(f(lst->content));
		if (!(elem->next))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		elem = elem->next;
	}
	return (first);
}
