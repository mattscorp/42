/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:24 by mascorpi          #+#    #+#             */
/*   Updated: 2019/01/08 11:51:10 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>

int main(int ac, char **av)
/*
int	main()
  {
  char	*line;

  get_next_line(4865, &line);
  ft_putnbr(get_next_line(4865, &line));
  printf("%s\n", line);
  return (0);
  }*/
{
	char *line = NULL;
	char	**test;
	int fd;
	//int fd2;
	int ret;

	if (!(test = (char**)malloc(sizeof(char*))))
		exit(-1);
/*	if (ac != 2)
		return(0);
*/	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, test)) > 0)
	{
		ft_putstr(*test);
		free(*test);
		ft_putchar('\n');
	}
	if (line)
		free(line);
	ft_putnbr(ret);
	close(fd);
	return (0);
}
