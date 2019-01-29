/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:32:33 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/29 18:07:19 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>


int		main(int ac, char **av)
{
	char *str;
	double f;

	f = 891478.486 * 2545;
	str = (char *)malloc(sizeof(char) * 3);
	str[0] = '4';
	str[1] = '2';
	str[2] = '\0';
	printf("%lf\n", f);
	puts("*********");
	ft_printf("%lf\n", f);

	return (0);
}
