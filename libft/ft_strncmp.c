/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:29:33 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/18 18:53:35 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while ((s1[i] && s2[i]) && n > i + 1)
		{
			if (s1[i] != s2[i])
				return (((unsigned char*)(s1))[i] - ((unsigned char*)(s2))[i]);
			i++;
		}
		return (((unsigned char*)(s1))[i] - ((unsigned char*)(s2))[i]);
	}
	return (0);
}
