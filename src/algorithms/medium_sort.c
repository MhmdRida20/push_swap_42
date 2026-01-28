/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:37:31 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 18:37:34 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_index_position(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_index = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_push_swap *ps)
{
	int	min_pos;
	int	size;

	size = ps->stack_a->size;
	min_pos = find_min_index_position(ps->stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(ps, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(ps, 1);
			min_pos++;
		}
	}
	pb(ps);
}

void	medium_sort(t_push_swap *ps)
{
	int original_size;
	int pushed;

	original_size = ps->stack_a->size;
	pushed = 0;
	while (ps->stack_a->size > 3)
	{
		push_min_to_b(ps);
		pushed++;
	}
	simple_sort(ps);
	while (pushed > 0)
	{
		pa(ps);
		pushed--;
	}
}