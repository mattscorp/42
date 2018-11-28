/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:21:46 by mascorpi          #+#    #+#             */
/*   Updated: 2018/11/28 15:51:58 by mascorpi         ###   ########.fr       */
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

	i = 0;
	j = 0;
	while (read_tot[i])
	{
		if (read_tot[i] == '\n')
			break ;
		i++;
	}
	if (!(rtn = (char *)malloc(sizeof(*rtn) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		rtn[j] = read_tot[j];
		j++;
	}
	rtn[j] = '\0';
	return (rtn);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tot[255];
	char			*tot_tmp;
	char			read_tmp[BUFF_SIZE + 1];
	int				nb_read;

	if ((read(fd, read_tmp, 0) < 0))
		return (-1);
	if (!(tot[fd]))
		tot[fd] = ft_strnew(1);
	while ((nb_read = read(fd, read_tmp, BUFF_SIZE)) > 0)
	{
		tot_tmp = tot[fd];
		read_tmp[nb_read] = '\0';
		tot[fd] = ft_strjoin(tot[fd], read_tmp);
		free(tot_tmp);
	}
	if (nb_read < 0)
		return (-1);
	if (*tot[fd] == '\0')
		return (0);
	*line = ft_line(tot[fd]);
	tot_tmp = tot[fd];
	tot[fd] = ft_strsub(tot[fd], ft_cl(tot[fd]), ft_strlen(tot[fd]));
	free(tot_tmp);
	return (1);
}
