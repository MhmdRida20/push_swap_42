/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 04:29:11 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/02 20:01:37 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_push_swap *ps, int print)
{
	if (ps->stack_a->size < 2)
		return ;
	swap_top_two(ps->stack_a);
	ps->op_count++;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_push_swap *ps, int print)
{
	if (ps->stack_b->size < 2)
		return ;
	swap_top_two(ps->stack_b);
	ps->op_count++;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_push_swap *ps)
{
	if (!ps)
		return ;
	swap_top_two(ps->stack_a);
	swap_top_two(ps->stack_b);
	ps->op_count++;
	ft_printf("ss\n");
}
