/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:08:20 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 18:53:44 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	calculate_disorder(t_stack *stack)
{
	int		inversions;
	t_node	*current;
	t_node	*compare;
	int		max_inversions;

	if (!stack || stack->size <= 1)
		return (0.0);
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
	max_inversions = stack->size * (stack->size - 1) / 2;
	if (max_inversions == 0)
		return (0.0);
	return ((double)inversions / (double)max_inversions);
}
