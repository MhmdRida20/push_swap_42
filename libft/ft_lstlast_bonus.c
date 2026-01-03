/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:30:30 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:25:42 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end;

	if (lst == NULL)
		return (0);
	end = lst;
	while (end->next != NULL)
	{
		end = end->next;
	}
	return (end);
}
