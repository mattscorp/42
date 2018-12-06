/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:21:46 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/06 17:53:42 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_cl(char *read_tot)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (read_tot[i])
	{
		if (read_tot[i] == '\n')
			break ;
		i++;
	}
	if (read_tot[i] == '\0')
		return (i);
	while (j < i)
		j++;
	return (j + 1);
}

static char			*ft_line(char *read_tot)
{
	char	*rtn;
	int		i;
	int		j;
	int		k;

	k = 1;
	i = 0;
	j = 0;
	while (read_tot[i])
	{
		if (read_tot[i] == '\n')
			break ;
		i++;
	}
	if (read_tot[i] == '\0')
		k--;
	if (!(rtn = (char *)malloc(sizeof(*rtn) * i + k)))
		return (NULL);
	while (j < i)
	{
		rtn[j] = read_tot[j];
		j++;
	}
	rtn[j] = '\0';
	return (rtn);
}

static char			*ft_read_tot(char **tot, int fd)
{
	int		nb_read;
	char	*tot_tmp;
	char	read_tmp[BUFF_SIZE + 1];

	if (!tot[fd])
		tot[fd] = ft_strnew(1);
	while ((nb_read = read(fd, read_tmp, BUFF_SIZE)) > 0)
	{
		tot_tmp = tot[fd];
		read_tmp[nb_read] = '\0';
		tot[fd] = ft_strjoin(tot[fd], read_tmp);
		ft_strdel(&tot_tmp);
	}
	if (nb_read < 0)
		return (NULL);
	return (tot[fd]);
}

int					get_next_line(const int fd, char **line)
{
	char			*tot_tmp;
	static char		*tot[4864];

	if (fd < 0 || !line)
		return (-1);
	if (!(tot[fd] = ft_read_tot(tot, fd)))
		return (-1);
	if (!(*line = ft_line(tot[fd])))
		return (-1);
	if (*tot[fd] == '\0')
	{
		ft_strdel(&tot[fd]);
		return (0);
	}
	tot_tmp = tot[fd];
	tot[fd] = ft_strsub(tot[fd], ft_cl(tot[fd]), ft_strlen(tot[fd]));
	ft_strdel(&tot_tmp);
	return (1);
}
