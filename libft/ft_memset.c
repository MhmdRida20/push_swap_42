/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:18:48 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:26:30 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c1;

	str = (unsigned char *)s;
	c1 = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		str[i] = c1;
		i++;
	}
	return (str);
}
