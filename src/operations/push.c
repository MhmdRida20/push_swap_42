/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 04:23:21 by mrida             #+#    #+#             */
/*   Updated: 2026/01/03 05:17:32 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->size++;
}

void	pa(t_push_swap *ps, int print)
{
	push(ps->stack_a, ps->stack_b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_push_swap *ps, int print)
{
	push(ps->stack_b, ps->stack_a);
	if (print)
		ft_printf("pb\n");
}
