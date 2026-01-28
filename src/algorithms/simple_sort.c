/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:47:37 by mrida             #+#    #+#             */
/*   Updated: 2026/01/28 19:29:05 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void sort_two(t_push_swap *ps)
{
	if (ps->stack_a->top->index > ps->stack_a->top->next->index)
		sa(ps,1);
}

static void sort_three(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->stack_a->top->index;
	b = ps->stack_a->top->next->index;
	c = ps->stack_a->top->next->next->index;
	if (a > b && b < c && a < c)
		sa(ps, 1);
	else if (a > b && b > c)
	{
		sa(ps, 1);
		rra(ps, 1);
	}
	else if (a > b && b < c && a > c)
		ra(ps ,1);
	else if (a < b && b > c && a < c)
	{
		sa(ps, 1);
		ra(ps, 1);
	}
	else if (a < b && b > c && a > c)
		rra(ps, 1);
}

void simple_sort(t_push_swap *ps)
{
	if (ps->stack_a->size == 2)
		sort_two(ps);
	else if (ps->stack_a->size == 3)
		sort_three(ps);
}