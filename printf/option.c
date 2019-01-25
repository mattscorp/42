/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:58:37 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/24 16:13:16 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_zero(int space, int b, const char *restrict format, char *str)
{
	char	*rtn;
	int		i;

	i = ft_strlen(str);
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
		rtn[space] = '0';
		space--;
	}
	/*printf("rtn zero = %s\n", rtn);
	  printf("str zero = %d\n", str);
	  */ft_putstr(rtn);
	return ;
}

static void	print_hash(int space, int b, const char *restrict format, char *str)
{
	char	*rtn;
	char	*tmp;
	int		i;

	i = ft_strlen(str);
	//printf("space = %d\n", space);printf("i strlen = %d\n", i);
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
	//	printf("rtn = %s\n", rtn);
	//	printf("str = %d\n", str);
	ft_putstr(rtn);
	return ;
}

/*static void	print_sign(int space, int b, const char *restrict format, char *str)
{
	char	*rtn;
	char	*tmp;
	int		i;

	i = ft_strlen(str);
	//printf("space = %d\n", space);printf("i strlen = %d\n", i);
	if (i >= space)
	{
		ft_putstr(str);
		ft_putchar('\n');
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
	//	printf("rtn = %s\n", rtn);
	//	printf("str = %d\n", str);
	ft_putstr(rtn);
	return ;
}
*/
int			ft_sign(const char *restrict format, int *option, int i, char *str)
{
	int nbr;
	int	len;
	int	space;
	char *rtn;

	len = ft_strlen(str);
	space = ft_atoi(&format[i + 1]);
	nbr = ft_atoi(str);
	if (nbr < 0)
		space++;
	if (i >= space)
	{
		if (nbr > 0 && option[1] == 1)
			ft_putchar('+');
		ft_putnbr(nbr);
	}
	else 
	{

		if (!(rtn = (char*)malloc(sizeof(char) * (space + 1))))
			return(0) ;
		rtn[space + 1] = '\0';
		while (len >= 0)
		{
			rtn[space--] = str[len--];
			if (nbr > 0 && len < 0)
				rtn[space--] = '+';
		}
		while (space >= 0)
		{
			rtn[space] = ' ';
			space--;
		}
		ft_putstr(rtn);
	}
	i++;
	while (format[i] && ft_checkflag(&format[i], 0) != -1)
		i++;
	return (i);

}

int			ft_hashtag(const char *restrict format, int *option, int i, char *str)
{
	int		space;
	int		b;
	char	*nbr;
	int		start;

	start = i;

	/*	while (format[i] && format[i] != '#' && format[i] != ' '
		&& (!(format[i] >= '1' && format[i] <= '9')))
		i++;
		if (format[i] == '#' || format[i] == ' ')
		i++;

	//	while (format[i] && (!(format[i] >= '1' && format[i] <= '9')))
	//		i++;
	*/
	//	printf("i avant= %d\n", i);
	/*	while (format[i + 1])
		{
	//		printf("i pendent= %d\n", i);
	if (format[i] == '#'// && (format[i + 1] >= 0 && format[i + 1] <= 9))
	break;
	i++;
	}
	*///	printf("i = %d\n", i);
	space = ft_atoi(&format[i + 1]);
	if (space <= 0)
		space = ft_atoi(&format[start]);
	//	printf("space = %d\n", space);
	nbr = ft_itoa(space);
	//	printf("nbr = %s\n", nbr);
	b = ft_strlen(nbr) + 1;
	if (option[4] == 1 || option [2] == 1 || option[5] == 1)
		print_hash(space, b, format, str);
	if (option[3] == 1)
		print_zero(space, b, format, str);
	i++;
	while (format[i] && ft_checkflag_end(&format[i], 0) != -1)
		i++;
	//	printf("i == %d\n", i);
	return (i);
}

int			*ft_flags(const char *restrict format, int *option)
{
	int	i;
	//	int	*nb;

	i = 0;
	//	if (!(nb = (int*)malloc(sizeof(int) * 5)))
	//		return (NULL);
	//	while (i < 5)
	//		nb[i++] = 0;
	//	i = 0;

	while (format[i] && (!(format[i] >= 'a' && format[i] <= 'z')))
	{
		//		printf("format[i] =%c\n", format[i]);
		if (format[i] == '-')
		{
			option[0] = 1;

			option[1] = 0;
			option[2] = 0;
			option[3] = 0;
			option[4] = 0;

		}
		else if (format[i] == '+')
		{
			option[1] = 1;

			option[0] = 0;
			option[2] = 0;
			option[3] = 0;
			option[4] = 0;
		}
		else if (format[i] == ' ')
		{
			option[2] = 1;

			option[0] = 0;
			option[1] = 0;
			option[3] = 0;
			option[4] = 0;

		}
		else if (format[i] == '0' && (!(format[i - 1] >= '0' && format[i - 1] <= '9')))
		{
			//			printf("format[i] dans option 3 %c\n", format[i - 1]);
			option[3] = 1;

			option[0] = 0;
			option[1] = 0;
			option[2] = 0;
			option[4] = 0;
		}
		else if (format[i] == '#')
		{
			option[4] = 1;

			option[0] = 0;
			option[1] = 0;
			option[2] = 0;
			option[3] = 0;
			break;
		}
		i++;
	}
	if (option[0] == 0 && option[1] == 0 && option[2] == 0 && option[3] == 0
			&& option[4] == 0)
		option[5] = 1;
	return (option);
}
