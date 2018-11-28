/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:56:32 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/13 17:14:34 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			rtn[i] = f(tmp);
			i++;
		}
		rtn[i] = '\0';
		return (rtn);
	}
	return (NULL);
}
