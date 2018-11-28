/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:31:27 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/12 13:37:23 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	n_2;
	char	*tmp_s;
	char	c_2;

	n_2 = 0;
	tmp_s = (char *)s;
	c_2 = (char)c;
	while (n_2 < n)
	{
		if (tmp_s[n_2] == c_2)
			return (&tmp_s[n_2]);
		n_2++;
	}
	return (NULL);
}
