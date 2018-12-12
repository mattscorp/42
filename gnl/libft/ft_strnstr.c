/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:52:38 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/20 10:06:37 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_f, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*rtn;

	rtn = (char *)src;
	i = 0;
	if (!(to_f[i]))
		return (&rtn[i]);
	while (src[i] && i < len)
	{
		j = 0;
		while (to_f[j] && src[i] == to_f[j] && i < len)
		{
			i++;
			j++;
			k = i - j;
			if (!to_f[j])
				return (&rtn[k]);
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
