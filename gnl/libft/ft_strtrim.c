/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:48:37 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/14 14:42:17 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	int		start;
	char	*rtn;

	if (s)
	{
		start = 0;
		i = 0;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		end = ft_strlen((char *)s) - 1;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		end++;
		if (end < start)
			start = 0;
		if (!(rtn = (char*)malloc(sizeof(char) * (end - start + 1))))
			return (NULL);
		while (start < end)
			rtn[i++] = s[start++];
		rtn[i] = '\0';
		return (rtn);
	}
	return (NULL);
}
