/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:15:16 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/13 17:24:46 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;
	char			tmp;

	i = 0;
	if (s && *f)
	{
		while (s[i])
			i++;
		if (!(rtn = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			tmp = s[i];
			rtn[i] = f(i, tmp);
			i++;
		}
		rtn[i] = '\0';
		return (rtn);
	}
	return (NULL);
}
