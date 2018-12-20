/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:31:18 by ceaudouy          #+#    #+#             */
/*   Updated: 2018/12/20 18:58:13 by ceaudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		ft_checkpos(char *fgrid, char *tab, int f, int g)
{
	int		j;
	int		cnt;

	j = 0;
	cnt = 0;
	while (tab[j])
	{
		if (fgrid[f] == '.' && (tab[j] >= 65 && tab[j] <= 90))
			cnt++;
		if (tab[j] == '\n')
			f = (f + g - 4);
		j++;
		f++;
	}
	if (cnt == 4)
		return (0);
	return (1);
}

char	*ft_backtrack(char *fgrid, char **tab, int g, int i, int start)
{
	int			j;
	size_t		f;

//	printf("start = %d\n", start);
//	printf("i = %d\n", i);
	f = start;
//	printf("f = start avant while= %zu\n", f);
	while (tab[i])
	{
		if (f >= ft_strlen(fgrid))
		{
//			puts("FINAL EXIT");
	//		printf("%s\n", fgrid);
			return (fgrid);
		}
	//	printf("fgrid = \n%s\n", fgrid);

	//	printf("f  dans while= %zu\n", f);
	//	printf("tab[i] = \n%s\n", tab[i]);
		j = 0;
		while (tab[i][j] == '.' || tab[i][j] == '\n')
			j++;
		while (fgrid[f] != '.' && f < ft_strlen(fgrid))
			f++;
	//	printf("f = %zu\n", f);
		if ((ft_checkpos(fgrid, &tab[i][j], f, g) == 0))
		{
			while (tab[i][j])
			{
				if (fgrid[f] == '.' && (tab[i][j] >= 65 && tab[i][j] <= 90))
					fgrid[f] = tab[i][j];
				if (tab[i][j] == '\n')
					f = (f + g - 4);
				f++;
				j++;
			}
//			puts("EXIT");
	//		printf("j = %d\n", j);
			i++;
			f = 0;
		}
		else
			f++;
		if (f >= ft_strlen(fgrid) - 1)
		{
//			puts("lalalal");
			i--;
			j = 0;
			f = 0;
			start = 0;
			if ( i == -1)
			{
				return (ft_solve(tab, g + 1));
			}
			while (tab[i][j] == '.' || tab[i][j] == '\n') // caractere recheche
				j++;
			while (fgrid[start] != tab[i][j]) // derniere position commence
				start++; 
			start++; // pos + 1
			while (fgrid[f]) //dell caractere voulu
			{
				if (fgrid[f] == tab[i][j])
					fgrid[f] = '.';
				f++;
			}
//			puts("backtak");
			return (ft_backtrack(fgrid, tab, g, i, start));//start);
		}
	}
	return (fgrid);
}

char	*ft_solve(char **tab, int g)
{
	int		tot;
	char	*fgrid;
	
	tot = ((g + 1) * g);
	if (!(fgrid = (char *)malloc(sizeof(*fgrid) *(tot + 1))))
		return (NULL);
	ft_clear(fgrid, g);
	fgrid = ft_backtrack(fgrid, tab, g, 0, 0);
//	printf("solve fgrid \n%s\n", fgrid);
	return (fgrid);
}
