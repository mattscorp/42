/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:27:00 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/13 15:00:35 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rtn;
	size_t	i;

	i = 0;
	if (!(rtn = ((char*)malloc(sizeof(char) * size + 1))))
		return (NULL);
	while (i <= size)
	{
		rtn[i] = '\0';
		i++;
	}
	return (rtn);
}
