/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 04:23:21 by mrida             #+#    #+#             */
/*   Updated: 2026/02/02 20:45:20 by aalkhati         ###   ########.fr       */
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
}

void	pb(t_push_swap *ps)
{
	if (ps->stack_a->size == 0)
		return ;
	push(ps->stack_a, ps->stack_b);
	ft_printf("pb\n");
}
