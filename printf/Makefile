# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceaudouy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 14:20:35 by ceaudouy          #+#    #+#              #
#    Updated: 2019/01/22 15:10:31 by ceaudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = decimal.c octal.c print_addres.c flags.c option.c \
	  printf.c putlong.c libft/*.c

INCLUDE = printf.h

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

.c.o:
	$(CC) -c $^ -o $@ -I $(CFLAGS)

$(NAME) : $(OBJ) 
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
