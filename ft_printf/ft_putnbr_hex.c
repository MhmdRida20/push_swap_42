/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:05:15 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/28 19:14:43 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putnbr_hex_lowercase(unsigned int n)
{
	char	*base ;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex_lowercase(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putnbr_hex_uppercase(unsigned int n)
{
	char	*base ;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_putnbr_hex_uppercase(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}
