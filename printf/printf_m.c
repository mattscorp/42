/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:16:50 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 15:35:04 by mascorpi         ###   ########.fr       */
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
	if (c[i] == 'u')
	return (16);
	if (c[i] == 'x')
		return (21);
	if (c[i] == 'X')
		return (26);
	if (c[i] == 'l')
	{
		i++;
		if (c[i] == 'o')
			return (12);
		if (c[i] == 'u')
			return (17);
		if (c[i] == 'x')
			return (22);
		if (c[i] == 'd' || c[i] == 'i')
			return (4);
		if (c[i] == 'X')
			return (27);	}
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
	if (c[i] == 'u')
		return (14);
	if (c[i] == 'x')
		return (20);
	if (c[i] == 'X')
		return (25);	
	if (c[i] == 'h')
	{
		i++;
		if (c[i] == 'd' || c[i] == 'i')
			return (7);
		if (c[i] == 'o')
			return (9);		
		if (c[i] == 'u')
			return (15);
		if (c[i] == 'x')
			return (19);
		if (c[i] == 'X')
			return (24);
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
		if (c[i] == 'u')
			return (13);
		if (c[i] == 'x')
			return (18);
		if (c[i] == 'X')
			return (23);
		i++;
	}
	return (-1);
}

int		ft_par(const char *restrict format, va_list ap)
{
	int		i;
	int		*option;
	int		flag;
	char	*str;

	i = 0;
	if(!(option = (int*)malloc(sizeof(int) * 5)))
		return (0);
	while (i < 5)
		option[i++] = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				i++;	
			option = ft_flags(&format[i + 1], option);
			flag = ft_checkflag(&format[i + 1]);
			str = func[flag](ap);
			if (option[0] == 1 || option[1] == 1)
				i = ft_sign(format, option, i , str);
			if (option[4] == 1 || option[2] == 1 || option[3] == 1 || option[5] == 1)
				i = ft_hashtag(format, option, i, str);
			free(str);
/*			if (flag == 3 || flag == 6 || flag == 10 || flag == 11)
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
	func[13] = &ft_unsigned;
	func[14] = &ft_unsignedshort;
	func[15] = &ft_unsignedchar;
	func[16] = &ft_unsignedlong;
	func[17] = &ft_unsignedlonglong;
	func[18] = &ft_hex;
	func[19] = &ft_hex_char;
	func[20] = &ft_hex_short;
	func[21] = &ft_hex_long;
	func[22] = &ft_hex_longlong;
	func[23] = &ft_hex_x;
	func[24] = &ft_hex_x_char;
	func[25] = &ft_hex_x_short;
	func[26] = &ft_hex_x_long;
	func[27] = &ft_hex_x_longlong;
	va_start(ap, format);
	ft_par(format, ap);
	va_end(ap);
	return (0);
}
