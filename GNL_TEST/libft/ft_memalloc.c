/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:25:54 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/13 13:52:02 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*rtn;
	size_t	i;

	i = 0;
	if (!(rtn = ((void*)malloc(sizeof(size_t) * size + 1))))
		return (NULL);
	while (i < size)
	{
		rtn[i] = '\0';
		i++;
	}
	return ((void*)(rtn));
}
