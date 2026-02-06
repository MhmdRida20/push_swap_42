/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 04:23:21 by mrida             #+#    #+#             */
/*   Updated: 2026/02/06 14:12:26 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	from->size--;
	node->next = to->top;
	to->top = node;
	to->size++;
}

void	pa(t_push_swap *ps)
{
	if (ps->stack_b->size == 0)
		return ;
	push(ps->stack_b, ps->stack_a);
	ft_printf("pa\n");
	ps->operations++;
}

void	pb(t_push_swap *ps)
{
	if (ps->stack_a->size == 0)
		return ;
	push(ps->stack_a, ps->stack_b);
	ft_printf("pb\n");
	ps->operations++;
}
