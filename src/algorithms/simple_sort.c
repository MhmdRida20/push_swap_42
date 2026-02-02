/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:47:37 by mrida             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/30 14:04:46 by mrida            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 19:52:07 by aalkhati         ###   ########.fr       */
>>>>>>> 5d46b16 (hh)
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

<<<<<<< HEAD
static void	sort_two(t_push_swap *ps)
{
	if (ps->stack_a->top->index > ps->stack_a->top->next->index)
		sa(ps, 1);
}

static void	sort_three(t_push_swap *ps)
=======
static int	find_min_position(t_stack *stack)
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

static void	rotate_min_to_top(t_push_swap *ps)
>>>>>>> 5d46b16 (hh)
{
	int	min_pos;
	int	size;

	size = ps->stack_a->size;
	min_pos = find_min_position(ps->stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(ps, 1);
			min_pos--;
		}
	}
<<<<<<< HEAD
	else if (a > b && b < c && a > c)
		ra(ps, 1);
	else if (a < b && b > c && a < c)
=======
	else
>>>>>>> 5d46b16 (hh)
	{
		while (min_pos < size)
		{
			rra(ps, 1);
			min_pos++;
		}
	}
}

void	simple_sort(t_push_swap *ps)
{
<<<<<<< HEAD
	if (ps->stack_a->size == 2)
		sort_two(ps);
	else if (ps->stack_a->size == 3)
		sort_three(ps);
=======
	int	total;

	total = ps->stack_a->size;
	while (ps->stack_a->size > 0)
	{
		rotate_min_to_top(ps);
		pb(ps);
	}
	while (ps->stack_b->size > 0)
		pa(ps);
>>>>>>> 5d46b16 (hh)
}
