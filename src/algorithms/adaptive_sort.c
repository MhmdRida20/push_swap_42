/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:38:28 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 18:39:46 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	adaptive_sort(t_push_swap *ps)
{
	int	size;

	if (!ps || !ps->stack_a)
		return ;
	size = ps->stack_a->size;
	if (size <= 1)
		return ;
	else if (size == 2)
		simple_sort(ps);
	else if (size == 3)
		simple_sort(ps);
	else if (size <= 5)
		medium_sort(ps);
	else
		complex_sort(ps);
}