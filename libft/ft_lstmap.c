/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:02:24 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/22 15:58:49 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!lst)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	first = new;
	new->next = new;
	ft_memcpy(new, f(lst), sizeof(t_list));
	while (lst->next)
	{
		if (!(new->next = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		ft_memcpy(new->next, f(lst->next), sizeof(t_list));
		lst = lst->next;
		new = new->next;
	}
	return (first);
}
