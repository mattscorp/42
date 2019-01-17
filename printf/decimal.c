/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:20:17 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/17 18:14:45 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_decimal(va_list ap)
{
	ft_putnbr(va_arg(ap, int));
	return (0);
}

int		ft_string(va_list ap)
{
	ft_putstr(va_arg(ap, char*));
	return (0);
}

int		ft_longlong(va_list ap)
{
	long long nb;

	nb = va_arg(ap, long long int);
	ft_putlonglong(nb);
	return (0);
}

int		ft_long(va_list ap)
{
	long int	nb;

	nb = va_arg(ap, long int);
	ft_putlong(nb);
	return (0);
}

int		ft_char(va_list ap)
{
	ft_putchar(va_arg(ap, int));
	return (0);
}
