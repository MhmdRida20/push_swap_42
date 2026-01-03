/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:06:33 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/28 19:14:30 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(char spec, va_list lst)
{
	unsigned int	ui;

	if (spec == 'x')
	{
		ui = va_arg(lst, unsigned int);
		return (ft_putnbr_hex_lowercase(ui));
	}
	else if (spec == 'X')
	{
		ui = va_arg(lst, unsigned int);
		return (ft_putnbr_hex_uppercase(ui));
	}
	return (0);
}
