/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 05:51:30 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/06 13:29:21 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	free_push_swap(t_push_swap *ps)
{
	if (!ps)
		return ;
	if (ps->stack_a)
		free_stack(ps->stack_a);
	if (ps->stack_b)
		free_stack(ps->stack_b);
	free(ps);
}

t_push_swap	*init_push_swap(void)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
	ps->stack_a = init_stack();
	ps->stack_b = init_stack();
	if (!ps->stack_a || !ps->stack_b)
	{
		free_push_swap(ps);
		return (NULL);
	}
	ps->operations = NULL;
	ps->op_count = 0;
	ps->disorder = 0.0;
	ps->strategy = ADAPTIVE;
	return (ps);
}
