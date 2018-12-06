/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:49:07 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/16 13:18:23 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_print_itoa(char *rtn, int n, int digit)
{
	int end;

	digit--;
	end = digit;
	while (n >= 10)
	{
		rtn[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
	if (n >= 0 && n <= 9)
	{
		rtn[digit - 1] = n + '0';
		digit--;
	}
	rtn[end] = '\0';
	return (rtn);
}

static int	ft_count_digit(int n)
{
	int d;

	d = 1;
	if (n == 0)
		d = 2;
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char		*ft_itoa(int n)
{
	int		neg;
	int		digit;
	int		i;
	char	*rtn;

	neg = 0;
	i = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
		i++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = ft_count_digit(n) + neg;
	if (!(rtn = (char*)malloc(sizeof(*rtn) * digit)))
		return (NULL);
	if (neg == 1)
		rtn[0] = '-';
	return (ft_print_itoa(rtn, n, digit));
}
