/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:49:15 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/18 18:36:46 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	n_2;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	n_2 = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	if (n > 0)
	{
		while (n_2 < n)
		{
			if (tmp_s1[n_2] == tmp_s2[n_2])
				n_2++;
			else
				return (tmp_s1[n_2] - tmp_s2[n_2]);
		}
		return (tmp_s1[n_2 - 1] - tmp_s2[n_2 - 1]);
	}
	return (0);
}
