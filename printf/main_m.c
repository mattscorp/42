/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:32:33 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/25 18:30:46 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	char *str;
	int n;
	float	f;

	f = -13.99815;

	str = (char *)malloc(sizeof(char) * 3);
	str = "bonjout";
	n = 123456789;
	printf("%f\n", f);

	puts("\nwaza\n");
	
	ft_printf("%f\n", f);

	return (0);
}
