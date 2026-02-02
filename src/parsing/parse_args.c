/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:19:49 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/31 16:17:12 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	cleanup_and_error(char **nums)
{
	free_split(nums);
	print_error();
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	process_arg(t_push_swap *ps, char *arg)
{
	char	**nums;
	int		i;
	long	val;
	t_node	*node;

	nums = ft_split(arg, ' ');
	if (!nums)
		print_error();
	i = 0;
	while (nums[i])
		i++;
	while (--i >= 0)
	{
		if (!is_valid_number(nums[i]))
			cleanup_and_error(nums);
		val = ft_atol(nums[i]);
		if (val > INT_MAX || val < INT_MIN
			|| has_duplicate(ps->stack_a, (int)val))
			cleanup_and_error(nums);
		node = create_node((int)val);
		if (!node)
			cleanup_and_error(nums);
		push_to_stack(ps->stack_a, node);
	}
	free_split(nums);
}

void	parse_args(t_push_swap *ps, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		process_arg(ps, argv[i]);
		i--;
	}
}
