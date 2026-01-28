/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:38:05 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 18:51:49 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (20);
	else
		return (35);
}

static int	find_in_range(t_stack *stack, int start, int end)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index >= start && current->index < end)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	push_chunk_to_b(t_push_swap *ps, int chunk_start, int chunk_end)
{
	int	pushed;

	pushed = 0;
	while (pushed < chunk_end - chunk_start && ps->stack_a->size > 0)
	{
		if (ps->stack_a->top->index >= chunk_start
			&& ps->stack_a->top->index < chunk_end)
		{
			pb(ps);
			pushed++;
		}
		else if (find_in_range(ps->stack_a, chunk_start, chunk_end))
			ra(ps, 1);
		else
			break ;
	}
}

static int	find_max_position(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_pos;
	int		pos;

	current = stack->top;
	max_index = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	push_max_to_a(t_push_swap *ps)
{
	int	max_pos;
	int	size;

	size = ps->stack_b->size;
	max_pos = find_max_position(ps->stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rb(ps, 1);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < size)
		{
			rrb(ps, 1);
			max_pos++;
		}
	}
	pa(ps);
}

void	complex_sort(t_push_swap *ps)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	total;

	chunk_size = get_chunk_size(ps->stack_a->size);
	total = ps->stack_a->size;
	chunk_start = 0;
	while (ps->stack_a->size > 0)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > total)
			chunk_end = total;
		push_chunk_to_b(ps, chunk_start, chunk_end);
		chunk_start = chunk_end;
	}
	while (ps->stack_b->size > 0)
		push_max_to_a(ps);
}