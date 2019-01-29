/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:32:45 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/25 18:30:59 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_approx(char *deci)
{
	int	i;

	i = ft_strlen(deci);
	i--;
	printf("i = %d\n", i);
	 while(deci[i] == '9' )
	{
		deci[i] = '0';
		i--;
	
		if (deci[i] != '9')
		{
			deci[i] = deci[i] + 1;
			break;
		}
	}
/*	i = ft_strlen(deci);
	i--;
	printf("iii = %d\n", i);
	printf("idecii = %c\n", deci[i]);
		if (deci[i] < '5')
		{
			deci[i] = deci[i] + 1;
		}	
//	}
//	while (deci[i])
//	{
//		if (!(deci[i] >= '0' && deci [i] <= '9'))
//			deci[i] = '0';
//		i++;
//	}
*/	return (deci);
}

char    *ft_float(va_list ap)
{
	float   f;
	long	tmp;
	char	*rtn;
	char	*deci;
	int	len;

	f = va_arg(ap, double);
	tmp = f;
	len = ft_strlen(ft_itoalong(tmp));
	if (!(rtn = (char*)malloc(sizeof(char) * (len + 7))))
		return (NULL);
	rtn = ft_itoalong(tmp);
	rtn[len] = '.';
	printf("f avant =%f\n", f);
	f = f - tmp;
	printf("f - tmp =%f\n", f);
	f = f * 1000000;
	printf("f * 1000000 =%f\n", f);
	if (!(deci = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	deci[7] = '\0';
	tmp = f;
	printf("tmp =%ld\n", tmp);

	deci = ft_itoalong(tmp);
	printf("deci  =%s\n", deci);
	deci = ft_approx(deci);
	printf("deci approx =%s\n", deci);

	if (f < 0)
		rtn = ft_strjoin(rtn, deci + 1);
	else	
		rtn = ft_strjoin(rtn, deci);
/*	len = 0;
	while(rtn[len])
	{
		if (!(rtn[len] >= '0' && rtn[len] <= '9') && !(rtn[len] == '.' ))
			rtn[len] = '0';
		len++;
		printf("len = %d\n", len);
	}
*/	printf("rtn FINAL = %s\n", rtn);
	return (rtn);
}
