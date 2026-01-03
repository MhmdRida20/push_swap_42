/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:07:02 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/28 19:07:05 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(char s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putnbr_hex(unsigned long n);
int	ft_putstr(char *s);
int	ft_print_pointer(void *ptr);
int	ft_putnbr_hex_lowercase(unsigned int n);
int	ft_putnbr_hex_uppercase(unsigned int n);
int	ft_hexa(char spec, va_list lst);

#endif