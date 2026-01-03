/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:06:34 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:23:50 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb >= __SIZE_MAX__ / size)
		return (0);
	arr = (void *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}
