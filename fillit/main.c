/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:17:59 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/20 11:30:36 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_read(int fd, char **tab)
{
	int		i;
	char	*buf;
	int		ret;

	i = 0;
	buf = ft_strnew(21); 
	while (i < 26)
		tab[i++] = NULL;
	i = 0;
	while ((ret = read(fd, buf, 21) > 0))
	{
		tab[i] = ft_strdup(buf);
		ft_bzero(buf, 21);
		if (ft_checkerror(tab[i]) == 1 || ft_check_tetri(tab[i]) == 1 || 
				i == 27)
			return (NULL);
		i++;
	}
	ft_strdel(&buf);
	if (ret < 0 || (ret == 0 && !tab[0]))
		return (NULL);
	if (ft_check_end(tab[i - 1]) == 1)
		return (NULL);
	tab[i] = 0;
	return (tab);
}

static void		ft_exec(char **tab)
{
	int		g;
	char	*grid;

	g = ft_grid(tab);
	ft_letter(tab);
	grid = ft_solve(tab, g);
	ft_putstr(grid);
	//ft_strdel(&grid); free qlqchose non aloue d apres fsanitize
}

int				main(int ac, char **av)
{
	int		fd;
	char	**tab;
	int		i;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit sample.fillit\n");
		return (0);
	}
	if (!(tab = (char**)malloc(sizeof(*tab) * 27)))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!(tab = ft_read(fd, tab)))
	{
		ft_putstr("error\n");
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		ft_strdel(tab);
		close(fd);
		return (0);
	}
	ft_exec(tab);
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
	close(fd);
	return (0);
}
