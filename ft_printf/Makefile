# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 19:07:33 by aalkhati          #+#    #+#              #
#    Updated: 2025/11/28 19:13:21 by aalkhati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f

SRCS := ft_printf.c \
ft_putchar.c ft_putnbr_hex.c \
ft_putnbr_unsigned.c \
ft_putnbr.c \
ft_putstr.c \
ft_hexa.c \
ft_print_pointer.c

OBJS    := $(SRCS:.c=.o)

INCS    := ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all