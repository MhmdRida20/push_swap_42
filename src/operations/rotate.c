/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:13:33 by mrida             #+#    #+#             */
/*   Updated: 2026/01/03 05:29:55 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	first->prev = stack->bottom;
	stack->bottom->next = first;
	stack->bottom = first;
}

void	ra(t_push_swap *ps, int print)
{
	rotate(ps->stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_push_swap *ps, int print)
{
	rotate(ps->stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_push_swap *ps, int print)
{
	rotate(ps->stack_a);
	rotate(ps->stack_b);
	if (print)
		ft_printf("rr\n");
}
