/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 04:29:11 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 18:44:07 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

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
	if (print)
		ft_printf("sa\n");
}

void	sb(t_push_swap *ps, int print)
{
	if (ps->stack_b->size < 2)
		return ;
	swap_top_two(ps->stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_push_swap *ps)
{
	sa(ps, 0);
	sb(ps, 0);
	ft_printf("ss\n");
}
