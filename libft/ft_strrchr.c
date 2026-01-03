/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:26:13 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:27:10 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occ;

	last_occ = 0;
	while (*s != '\0')
	{
		if (*s == (char )c)
		{
			last_occ = s;
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_occ);
}
