/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:32:33 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/24 11:28:04 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(int ac, char **av)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 3);
	str = "ya ya ya";
	printf("la bonne = \nhello world %s\n et %s\n %p\n", "salut le monde", "une autre chiaine", str);
	ft_printf("hello world %s\n et %s\n %p\n", "salut le monde", "une autre chiaine", str);

	return (0);
}
