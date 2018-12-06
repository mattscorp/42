/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_skip_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:08:02 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/23 19:33:51 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_skip_char(char *str, char c)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j++;
		i++;
	}
	if (!(rtn = (char *)malloc(sizeof(*str) * (j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		rtn[j++] = str[i++];
	}
	rtn[i] = '\0';
	return (rtn);
}
