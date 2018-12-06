/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:50:43 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/23 13:54:35 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprime(int nb)
{
	int	i;

	if (nb)
	{
		i = nb / 2;
		if (i <= 0)
			return (0);
		while (nb % i != 0 && i > 1)
		{
			i--;
			if (i == 1)
				return (1);
		}
		return (0);
	}
	return (0);
}
