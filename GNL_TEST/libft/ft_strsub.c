/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:39:28 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/06 16:18:17 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	start_i;
	char			*rtn;
	size_t			len_i;

	len_i = 0;
	start_i = 0;
	if (s)
	{
		s = (char*)s;
		if (!(rtn = (char*)malloc(sizeof(*rtn) * len + 1)))
			return (NULL);
		while (len_i < len)
		{
			rtn[start_i] = s[start];
			start_i++;
			start++;
			len_i++;
		}
		rtn[start_i] = '\0';
		return (rtn);
	}
	return (NULL);
}
