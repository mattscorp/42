/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:24 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/06 17:53:45 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>

int main(int ac, char **av)
{
	char *line = 0;
	int fd;

	if (ac != 2)
		return(0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		free(line);
		ft_putchar('\n');
	}
	free(line);
	close(fd);
	return (0);
}
