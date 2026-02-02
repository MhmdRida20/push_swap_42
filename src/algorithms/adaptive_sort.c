/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:38:28 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/02 20:40:39 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_two(t_push_swap *ps)
{
	if (ps->stack_a->top->index > ps->stack_a->top->next->index)
		sa(ps, 1);
}

static void	sort_three(t_push_swap *ps)
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
		ra(ps, 1);
	else if (a < b && b > c && a < c)
	{
		sa(ps, 1);
		ra(ps, 1);
	}
	else if (a < b && b > c && a > c)
		rra(ps, 1);
}

void	adaptive_sort(t_push_swap *ps)
{
	int	size;

	if (!ps || !ps->stack_a)
		return ;
	size = ps->stack_a->size;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_two(ps);
	else if (size == 3)
		sort_three(ps);
	else if (size <= 20)
		simple_sort(ps);
	else if (size <= 100)
		medium_sort(ps);
	else
		complex_sort(ps);
}
