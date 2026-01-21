/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:08:20 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/21 20:06:31 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	compute_disorder(t_stack *stack)
{
	int		inversions;
	t_node	*current;
	t_node	*compare;

	inversions = 0;
	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value > compare->value)
				inversions++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (stack->size <= 1)
		return (0.0);
	return ((double)inversions / (stack->size * (stack->size - 1) / 2));
}
