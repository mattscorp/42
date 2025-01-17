/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalonglong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:48:40 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 10:48:41 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(long long n)
{
	int len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void		ft_print(long long n, char *tab, int neg, int len)
{
	int		i;

	i = len;
	while (i >= 0)
	{
		tab[i] = (char)((n) % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg == 1)
		tab[0] = '-';
	tab[len + 1] = '\0';
}

char			*ft_itoalonglong(long long n)
{
	int		neg;
	int		len;
	char	*tab;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_len(n) + neg;
	if (!(tab = (char*)malloc(sizeof(*tab) * len + 2)))
		return (0);
	ft_print(n, tab, neg, len);
	return (tab);
}
