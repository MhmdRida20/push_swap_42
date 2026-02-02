/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:34:30 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/02 20:02:37 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (stack->size < 2)
		return ;
	last = stack->top;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_push_swap *ps, int print)
{
	reverse_rotate(ps->stack_a);
	ps->op_count++;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_push_swap *ps, int print)
{
	reverse_rotate(ps->stack_b);
	ps->op_count++;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_push_swap *ps)
{
	reverse_rotate(ps->stack_a);
	reverse_rotate(ps->stack_b);
	ps->op_count++;
	ft_printf("rrr\n");
}
