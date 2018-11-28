/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:36:29 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/13 16:16:06 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *src, const char *to_find)
{
	int		i;
	int		j;
	int		k;
	char	*rtn;

	rtn = (char *)src;
	i = 0;
	if (!(to_find[i]))
		return (&rtn[i]);
	while (src[i])
	{
		j = 0;
		while (src[i] == to_find[j])
		{
			i++;
			j++;
			k = i - j;
			if (to_find[j] == '\0')
				return (&rtn[k]);
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
