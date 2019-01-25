/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:16:50 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/25 15:04:26 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_l(const char *c)
{
	if (*c == 'o')
		return (11);
	if (*c == 'd' || *c == 'i')
		return (3);
	if (*c == 'u')
		return (16);
	if (*c == 'x')
		return (21);
	if (*c == 'X')
		return (26);
	if (*c == 'l')
	{
		c++;
		if (*c == 'o')
			return (12);
		if (*c == 'u')
			return (17);
		if (*c == 'x')
			return (22);
		if (*c == 'd' || *c == 'i')
			return (4);
		if (*c == 'X')
			return (27);
	}
	return (-1);
}

int		ft_h(const char *c)
{
	if (*c == 'd' || *c == 'i')
		return (6);
	if (*c == 'o')
		return (10);
	if (*c == 'u')
		return (14);
	if (*c == 'x')
		return (20);
	if (*c == 'X')
		return (25);
	if (*c == 'h')
	{
		c++;
		if (*c == 'd' || *c == 'i')
			return (7);
		if (*c == 'o')
			return (9);
		if (*c == 'u')
			return (15);
		if (*c == 'x')
			return (19);
		if (*c == 'X')
			return (24);
	}
	return (-1);
}

int		ft_checkflag(const char *c, int i)
{
	while (c[i])
	{
		if (c[i] == 'd' || c[i] == 'i')
			return (0);
		if (c[i] == 's')
			return (1);
		if (c[i] == 'c')
			return (2);
		if (c[i] == 'l')
			return (ft_l(&c[i + 1]));
		if (c[i] == 'h')
			return (ft_h(&c[i + 1]));
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
		if (c[i] == 'f')
			return (28);
		i++;
	}
	return (-1);
}

int			ft_par(const char *restrict format, va_list ap)
{
	int		i;
	int		*option;
	int		flag;
	char	*str;

	i = 0;
	if (!(option = (int*)malloc(sizeof(int) * 6)))
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
			printf("option[0] = %d\n", option[0]);
			printf("option[1] = %d\n", option[1]);
			printf("option[2] = %d\n", option[2]);
			printf("option[3] = %d\n", option[3]);
			printf("option[4] = %d\n", option[4]);
			printf("option[5] = %d\n", option[5]);
			flag = ft_checkflag(&format[i + 1], 0);
			str = func[flag](ap);
			
			if (option[4] == 1 || option[2] == 1 || option[3] == 1 || option[5] == 1)
				i = ft_hashtag(format, option, i, str);
			else if ((option[0] == 1 || option[1] == 1) && option[3] != 1)
				i = ft_sign(&format[i + 1], option, i, str);	if (flag != 1)
			free(str);
		}
		if (format[i] && ft_strlen(format) > i)
			ft_putchar(format[i]);
		i++;
	}
	return (0);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list ap;

	ft_func();
	va_start(ap, format);
	ft_par(format, ap);
	va_end(ap);
	return (0);
}
