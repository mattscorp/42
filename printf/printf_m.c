/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:16:50 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/23 11:34:13 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_l(const char *c)
{
	int		i;

	i = 1;
	if (c[i] == 'o')
		return (11);
	if (c[i] == 'd' || c[i] == 'i')
		return (3);
	if (c[i] == 'l')
	{
		i++;
		if (c[i] == 'o')
			return (12);
		if (c[i] == 'd' || c[i] == 'i')
			return (4);
	}
	return (-1);
}
static int	ft_h(const char *c)
{
	int		i;

	i = 1;
	if (c[i] == 'd' || c[i] == 'i')
		return (6);
	if (c[i] == 'o')
		return (10);		
	if (c[i] == 'h')
	{
		i++;
		if (c[i] == 'd' || c[i] == 'i')
			return (7);
		if (c[i] == 'o')
			return (9);		
	}
	return (-1);
}

static int	ft_checkflag(const char *c)
{
	int	i;

	i = 0;
	while(c[i])
	{
		if (c[i] == 'd' || c[i] == 'i')
			return (0);
		if (c[i] == 's')
			return (1);
		if	(c[i] == 'c')
			return (2);
		if (c[i] == 'l')
			return (ft_l(c));
		if (c[i] == 'h')
			return (ft_h(c));
		if (c[i] == 'o')
			return (8);
		if (c[i] == 'p')
			return (5);
		i++;
	}
	return (-1);
}

int		ft_par(const char* restrict format, va_list ap)
{
	int		i;
	int		*option;
	int		flag;
	char	*str;

	i = 0;
	if(!(option = (int*)malloc(sizeof(int) * 6)))
		return (0);
	while (i < 6)
		option[i++] = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				i++;	
			option = ft_flags(&format[i + 1], option);
			
			printf("option [0] = %d\n",option[0]);
			printf("option [1] = %d\n",option[1]);
			printf("option [2] = %d\n",option[2]);
			printf("option [3] = %d\n",option[3]);
			printf("option [4] = %d\n",option[4]);
			printf("option [5] = %d\n",option[5]);
			
			


			flag = ft_checkflag(&format[i + 1]);
			str = func[flag](ap);
		//	if (option[0] == 1 || option[1] == 1)
		//		i = ft_sign(&format[i + 1], ap, option);
			if (option[4] == 1 || option[2] == 1 || option[3] == 1 || option[5] == 1)
				i = i + ft_hashtag(format, option, i + 1, str);
			
			
			free(str);
/*
			if (flag == 3 || flag == 6 || flag == 10 || flag == 11)
				i++;
			if (flag == 4 || flag == 7 || flag == 9 || flag == 12)
				i += 2;
*/
		}
		if (format[i] && ft_strlen(format) > i)
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
	func[3] = &ft_long_d;
	func[4] = &ft_longlong_d;
	func[5] = &ft_pointer;
	func[6] = &ft_short_d;
	func[7] = &ft_char_d;
	func[8] = &ft_octal;
	func[9] = &ft_octal_char;
	func[10] = &ft_octal_short;
	func[11] = &ft_octal_long;
	func[12] = &ft_octal_longlong;
	va_start(ap, format);
	ft_par(format, ap);
	va_end(ap);
	return (0);
}
