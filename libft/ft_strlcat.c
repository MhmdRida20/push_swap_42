/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:46:28 by aalkhati          #+#    #+#             */
/*   Updated: 2025/10/31 14:41:49 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = 0;
	dlen = 0;
	while (dlen < size && dst[dlen] != '\0')
	{
		dlen++;
	}
	while (src[slen] != '\0')
	{
		slen++;
	}
	if (dlen == size)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && (dlen + i) < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
