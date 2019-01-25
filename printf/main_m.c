/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:32:33 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/25 14:29:34 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	char *str;
	int n;

	str = (char *)malloc(sizeof(char) * 3);
	str = "bonjout";
	n = 123456789;
	printf("%+020d\n      oui oui", n);

	puts("\nwaza\n");
	
	ft_printf("%+020d\n      oui oui", n);

	return (0);
}
