/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:58:37 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/25 15:06:26 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_zero(int space, int* option, const char *restrict format, char *str)
{
	char	*rtn;
	int		i;
	int		neg;

	neg = 0;
	i = ft_strlen(str);
	if (i >= space)
	{
		ft_putstr(str);
		return ;
	}
	if (!(rtn = (char*)malloc(sizeof(char) * (space + 1))))
		return ;
	rtn[space + 1] = '\0';
	if (str[0] == '-')
	{
		str[0] = '0';
		rtn[0] = '-';
		neg++;
	}
	while (i >= 0)
		rtn[space--] = str[i--];
	while (space >= 0)
	{
		rtn[space--] = '0';
		if (neg > 0 && space == 0)
			break;
	}
	if (option[1] == 1 && str[0] != '-')
		rtn[0] = '+';
	ft_putstr(rtn);
	return ;
}

static void	print_hash(int space, const char *restrict format, char *str, int *option)
{
	char	*rtn;
	char	*tmp;
	int		i;

	i = ft_strlen(str);
	if (option[1] == 1)
		ft_putchar('+');
	if (i >= space)
	{
		ft_putstr(str);
		return ;
	}
	if (!(rtn = (char*)malloc(sizeof(char) * (space + 1))))
		return ;
	rtn[space + 1] = '\0';
	while (i >= 0)
		rtn[space--] = str[i--];
	while (space >= 0)
	{
		rtn[space] = ' ';
		space--;
	}
	ft_putstr(rtn);
	return ;
}

int			ft_sign(const char *restrict format, int *option, int i, char *str)
{
	long	nbr;
	int		len;
	int		space;
	char	*rtn;

	space = 0;
	len = ft_strlen(str);
	if (option[0] == 0)
		space = ft_atoi(&format[i + 1]);
	nbr = ft_atoi(str);
	if (nbr < 0 || option[1] == 1)
		space++;
	if (i >= space)
	{
		if (nbr > 0 && option[1] == 1)
			ft_putchar('+');
		ft_putnbr(nbr);
	}
	if (option[1] == 1)
		print_hash(space, format, str, option);
	else
	{
		if (!(rtn = (char*)malloc(sizeof(char) * (space + 1))))
			return (0);
		rtn[space + 1] = '\0';
		while (len >= 0)
		{
			rtn[space--] = str[len--];
			if (nbr > 0 && len < 0 && option[0] == 0)
			{			
				rtn[space--] = '+';
			}
		}
		while (space >= 0)
		{
			rtn[space] = ' ';
			space--;
		}
		ft_putstr(rtn);
	}
	while (format[i] && ft_checkflag_end(&format[i], 0) == -1)
		i++;
	return (i + 2);
}

int			ft_hashtag(const char *restrict format, int *option, int i, char *str)
{
	int		space;
	int		b;
	char	*nbr;
	int		start;

	while (format[i] && (format[i] != '.' && format[i] != '0' && format[i] != '#'))
		i++;
	start = i;
//	printf("start = %d\n", start);
	space = ft_atoi(&format[i + 1]);
	if (space <= 0)
		space = ft_atoi(&format[start]);
	nbr = ft_itoa(space);
	b = ft_strlen(nbr) + 1;
//	printf("nbr = %s\n", nbr);
//	printf("space = %d\n", space);
//	printf("b = %d\n", b);
//	printf("str = %s\n", str);
//	printf("format = %s\n", format);
	if (option[4] == 1 || option[2] == 1 || option[5] == 1)
		print_hash(space, format, str, option);
	if (option[3] == 1 && ft_checkflag(&format[i], 0) != 1)
			print_zero(space, option, format, str);
//	printf("iii = %d\n", i);
	while (format[i] && ft_checkflag_end(&format[i], 0) == -1)
		i++;
//	printf("i3 = %d\n", i);
	return (i + 1);
}

int			*ft_flags(const char *restrict format, int *option)
{
	int	i;

	i = 0;
	while (format[i] && (!(format[i] >= 'a' && format[i] <= 'z')))
	{
		if (format[i] == '-')
		{
			option[0] = 1;
		//	option[1] = 0;
		//	option[2] = 0;
		//	option[3] = 0;
		//	option[4] = 0;
		}
		else if (format[i] == '+')
		{
			option[1] = 1;
		//	option[0] = 0;
		//	option[2] = 0;
		//	option[3] = 0;
		//	option[4] = 0;
		//	break;
		}
		else if (format[i] == ' ')
		{
			option[2] = 1;
		//	option[0] = 0;
		//	option[1] = 0;
		//	option[3] = 0;
		//	option[4] = 0;
		}
		else if ((format[i] == '0' || format[i] == '.') && 
				(!(format[i - 1] >= '0' && format[i - 1] <= '9')))
		{
			option[3] = 1;
		//	option[0] = 0;
		//	option[1] = 0;
		//	option[2] = 0;
		//	option[4] = 0;
		}
		else if (format[i] == '#')
		{
			option[4] = 1;
		//	option[0] = 0;
		//	option[1] = 0;
		//	option[2] = 0;
		//	option[3] = 0;
			break ;
		}
		i++;
	}
	if (option[0] == 0 && option[1] == 0 && option[2] == 0 && option[3] == 0
			&& option[4] == 0)
		option[5] = 1;
	return (option);
}
