/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:13:33 by mrida             #+#    #+#             */
/*   Updated: 2026/02/02 20:02:21 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_push_swap *ps, int print)
{
	if (!ps || !ps->stack_a)
		return ;
	rotate(ps->stack_a);
	ps->op_count++;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_push_swap *ps, int print)
{
	if (!ps || !ps->stack_b)
		return ;
	rotate(ps->stack_b);
	ps->op_count++;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_push_swap *ps)
{
	if (!ps)
		return ;
	rotate(ps->stack_a);
	rotate(ps->stack_b);
	ps->op_count++;
	ft_printf("rr\n");
}
