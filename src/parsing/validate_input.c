/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:31 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/02 22:46:01 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	validate_input(t_push_swap *ps)
{
	if (!ps || !ps->stack_a || ps->stack_a->size == 0)
	{
		free_push_swap(ps);
		print_error();
	}
	if (has_duplicates(ps->stack_a))
	{
		free_push_swap(ps);
		print_error();
	}
}
