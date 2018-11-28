/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:49:30 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/09 15:05:30 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rtn;

	rtn = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (&rtn[i]);
		i--;
	}
	return (NULL);
}
