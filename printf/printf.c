/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:16:50 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/17 18:14:39 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_checkflag(const char *c)
{
	if (*c == 'd')
		return (0);
	if (*c == 's')
		return (1);
	if	(*c == 'c')
		return (2);
	if (*c == 'l')
	{
		c++;
		if (*c == 'd')
			return (3);
		if (*c == 'l')
		{
			c++;
			if (*c == 'd')
				return (4);
		}
	}
	if (*c == 'p')
		return (5);
	return (-1);
}

int		ft_par(const char* restrict format, va_list ap)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	while (format[i])
	{
		j = 0;
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			   i++;	
		//	if (ft_checkflag(&format[i + 1]) == -1)
		//		ft_option(format, i, ap);
			else 
				flag = ft_checkflag(&format[i + 1]);
			func[flag](ap);
			i += 2;
			if (flag == 3)
				i++;
			if (flag == 4)
				i += 2;

		}
		ft_putchar(format[i]);
		i++;
	}
	return (0);
}

int		ft_printf(const char* restrict format, ...)
{
	va_list ap;

	func[0] = &ft_decimal;
	func[1] = &ft_string;
	func[2] = &ft_char;
	func[3] = &ft_long;
	func[4] = &ft_longlong;
	func[5] = &ft_pointer;
	va_start(ap, format);
	ft_par(format, ap);
	return (0);
}
