/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:59:44 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/31 13:52:05 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_print_itoa(long res, int digit, char *rtn)
{
	int	end;

	end = digit;
	while (res >= 10)
	{
		rtn[digit - 1] = res % 10 + '0';
		res /= 10;
		digit--;
	}
	if (res >= 0 && res <= 9)
	{
		rtn[digit - 1] = res + '0';
		digit--;
	}
	rtn[end] = '\0';
	return (rtn);
}

int		ft_count(long res)
{
	int	count;

	count = 1;
	if (res == 0)
		return (count + 1);
	while (res > 0)
	{
		res /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		digit;
	int		neg;
	long	res;
	char	*rtn;

	digit = 0;
	neg = 0;
	res = nbr;
	if (nbr < 0)
	{
		res = -res;
		neg++;
	}
	digit = ft_count(res) + neg;
	if (!(rtn = (char*)malloc(sizeof(char) * digit)))
		return (NULL);
	if (neg == 1)
		rtn[0] = '-';
	return (ft_print_itoa(res, digit - 1, rtn));
}
