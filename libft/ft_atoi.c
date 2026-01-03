/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:58:18 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:23:28 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	short	parity;
	int		number;

	parity = 0;
	number = 0;
	while (((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			parity++;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number *= 10;
		number += *nptr - 48;
		nptr++;
	}
	if (!(parity % 2))
		return (number);
	return (-number);
}
