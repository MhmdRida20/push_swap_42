/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:53:51 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/21 20:09:55 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_unindexed(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		has_unindexed;

	has_unindexed = 0;
	min_node = NULL;
	current = stack->top;
	while (current)
	{
		if (current->index == -1)
		{
			if (!has_unindexed || current->value < min_node->value)
			{
				min_node = current;
				has_unindexed = 1;
			}
		}
		current = current->next;
	}
	if (min_node)
		return (min_node->value);
	return (0);
}

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		index;

	index = 0;
	while (index < stack->size)
	{
		min_value = find_min_unindexed(stack);
		current = stack->top;
		while (current)
		{
			if (current->value == min_value && current->index == -1)
			{
				current->index = index;
				break ;
			}
			current = current->next;
		}
		index++;
	}
}
