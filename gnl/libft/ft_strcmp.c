/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:53:38 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/12 15:03:02 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char*)(s1))[i] - ((unsigned char*)(s2))[i]);
		i++;
	}
	return (((unsigned char*)(s1))[i] - ((unsigned char*)(s2))[i]);
}
