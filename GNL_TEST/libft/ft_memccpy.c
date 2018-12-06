/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:29:17 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/10 18:56:06 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			n_2;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	unsigned char	c_2;
	int				move;

	n_2 = 0;
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	c_2 = (unsigned char)c;
	move = 0;
	while (n_2 < n)
	{
		if (tmp_src[n_2] == c_2)
		{
			tmp_dst[n_2] = tmp_src[n_2];
			return (&tmp_dst[n_2 + 1]);
		}
		tmp_dst[n_2] = tmp_src[n_2];
		n_2++;
	}
	return (NULL);
}
