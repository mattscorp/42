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

static char	*ft_approx(char *rtn)
{
	int	i;

	i = ft_strlen(rtn);
	i--;
		if (rtn[i] >= 5)
		{
			rtn[i] = '0';
			rtn[i - 1] = rtn[i - 1] + 1;
		}
	return (rtn);
}

char    *ft_float(va_list ap)
{
    float   f;
	long	tmp;
	char	*rtn;
	char	*deci;
	int		len;

    f = va_arg(ap, double);
	tmp = f;
	len = ft_strlen(ft_itoalong(tmp));
	if (!(rtn = (char*)malloc(sizeof(char) * (len + 7))))
		return (NULL);
	rtn = ft_itoalong(tmp);
	rtn[len] = '.';
	f = f - tmp;
	f = f * 1000000;
	if (!(deci = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
    	tmp = f;
		deci = ft_itoalong(tmp);
		if (f < 0)
			rtn = ft_strjoin(rtn, deci + 1);
		else	
			rtn = ft_strjoin(rtn, deci);
	rtn = ft_approx(rtn);
		printf("rtn FINAL = %s\n", rtn);
	return (rtn);
}
