/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:23:46 by ceaudouy          #+#    #+#             */
/*   Updated: 2019/01/21 15:56:51 by mascorpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int		(*func[6])(va_list);
int		ft_printf(const char* restrict format, ...);
int		ft_decimal(va_list ap);
int		ft_string(va_list ap);
int		ft_char(va_list ap);
int		ft_long(va_list ap);
int		ft_longlong(va_list ap);
int		ft_long(va_list ap); 
void	ft_putlonglong(long long nb);
void	ft_putlong(long nb); 
int		ft_pointer(va_list ap);
int		*ft_flags(const char* restrict format);
#endif
