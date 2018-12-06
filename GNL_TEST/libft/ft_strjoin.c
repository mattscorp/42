/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:32:24 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/14 11:46:14 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*rtn;

	k = 0;
	if (s1 && s2)
	{
		i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		if (!(rtn = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while ((char)s1[k])
		{
			rtn[k] = (char)(s1[k]);
			k++;
		}
		i = 0;
		while ((char)s2[i])
		{
			rtn[k++] = (char)(s2[i]);
			i++;
		}
		rtn[k] = '\0';
		return (rtn);
	}
	return (NULL);
}
