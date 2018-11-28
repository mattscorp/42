/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:45:23 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/15 17:48:26 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_let(char const *s, char c, int i)
{
	int rtn;

	rtn = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		rtn++;
	}
	return (rtn);
}

static int		ft_count_w(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		word++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		p;
	int		len;
	char	**tab;

	i = 0;
	p = 0;
	if (!s || !(tab = (char**)malloc(sizeof(*tab) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			len = ft_count_let(s, c, i);
			tab[p] = ft_strsub(s, (unsigned int)i, (size_t)len);
			i = i + len;
			len = 0;
			p++;
		}
	}
	tab[p] = 0;
	return (tab);
}
