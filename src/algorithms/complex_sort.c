/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:38:05 by aalkhati          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/30 14:04:22 by mrida            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 19:41:28 by aalkhati         ###   ########.fr       */
>>>>>>> 5d46b16 (hh)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

<<<<<<< HEAD
=======
static int	get_chunk_size(int stack_size)
{
	if (stack_size <= 16)
		return (3);
	else if (stack_size <= 100)
		return (15);
	else if (stack_size <= 500)
		return (21);
	else
		return (35);
}

>>>>>>> 5d46b16 (hh)
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
	int	mid;

	pushed = 0;
	mid = chunk_start + (chunk_end - chunk_start) / 2;
	while (pushed < chunk_end - chunk_start && ps->stack_a->size > 0)
	{
		if (ps->stack_a->top->index >= chunk_start
			&& ps->stack_a->top->index < chunk_end)
		{
			pb(ps);
			pushed++;
			if (ps->stack_b->size > 1 && ps->stack_b->top->index < mid)
				rb(ps, 1);
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
	int	rotations;

	if (ps->stack_b->size == 0)
		return ;
	size = ps->stack_b->size;
	max_pos = find_max_position(ps->stack_b);
	if (max_pos == 0)
	{
		pa(ps);
		return ;
	}
	if (max_pos <= size / 2)
	{
		rotations = max_pos;
		while (rotations-- > 0)
			rb(ps, 1);
	}
	else
	{
		rotations = size - max_pos;
		while (rotations-- > 0)
			rrb(ps, 1);
	}
	pa(ps);
}

void	complex_sort(t_push_swap *ps)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	total;

	if (ps->stack_a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
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
