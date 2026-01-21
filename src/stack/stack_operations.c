/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 06:02:52 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/21 20:15:44 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_to_stack(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = stack->top;
		node->prev = NULL;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node	*detach_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
