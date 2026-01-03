/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:27:49 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:26:17 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*srcc;

	i = 0;
	desti = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		desti[i] = srcc[i];
		i++;
	}
	return (desti);
}
