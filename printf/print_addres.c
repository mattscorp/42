#include <stdio.h>
#include "libft/libft.h"
#include "printf.h"

// void ft_pointer(const void *p)
 int ft_pointer(va_list ap)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int 			i;
	
//	adr = (unsigned long) p;
	adr = (unsigned long) va_arg(ap, void*);
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putchar('0');
	ft_putchar('x');
	while (i < 9)
	{
		ft_putchar(res[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	*str;
	unsigned int yo;

	str = "bonjour";
	ft_pointer ((const void*)str);
	ft_printf(" %p\n", str);
	return (0);
}*/
