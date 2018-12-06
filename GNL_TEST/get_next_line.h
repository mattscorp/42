/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mascorpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:21:57 by mascorpi          #+#    #+#             */
/*   Updated: 2018/12/06 17:54:28 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

int	get_next_line(const int fd, char **line);
#endif
