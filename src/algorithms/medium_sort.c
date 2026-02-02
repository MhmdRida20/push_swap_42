/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:37:31 by aalkhati          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/30 14:04:37 by mrida            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 19:52:27 by aalkhati         ###   ########.fr       */
>>>>>>> 5d46b16 (hh)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static void	push_chunk_to_b(t_push_swap *ps, int chunk_start, int chunk_end)
{
	int	size;

	size = ps->stack_a->size;
	while (size > 0 && ps->stack_a->size > 0)
	{
		if (ps->stack_a->top->index >= chunk_start
			&& ps->stack_a->top->index < chunk_end)
		{
			pb(ps);
			size = ps->stack_a->size;
		}
		else
		{
			ra(ps, 1);
			size--;
		}
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

void	medium_sort(t_push_swap *ps)
{
<<<<<<< HEAD
	int	pushed;
=======
	int	chunk_size;
	int	total;
	int	chunk_start;
>>>>>>> 5d46b16 (hh)

	total = ps->stack_a->size;
	chunk_size = ft_sqrt(total);
	chunk_start = 0;
	while (ps->stack_a->size > 0)
	{
		push_chunk_to_b(ps, chunk_start, chunk_start + chunk_size);
		chunk_start += chunk_size;
	}
<<<<<<< HEAD
	simple_sort(ps);
	while (pushed > 0)
	{
		pa(ps);
		pushed--;
	}
=======
	while (ps->stack_b->size > 0)
		push_max_to_a(ps);
>>>>>>> 5d46b16 (hh)
}
