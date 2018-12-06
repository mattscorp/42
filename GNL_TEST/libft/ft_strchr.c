/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:34:59 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/12 14:02:05 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (&rtn[i]);
		i++;
	}
	if (c == '\0')
		return (&rtn[i]);
	return (NULL);
}
