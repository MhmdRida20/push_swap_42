/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:19:49 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/02 22:45:31 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	parse_split_args(t_push_swap *ps, char **nums)
{
	int		i;
	int		num;
	t_node	*node;
	char	*trimmed;
	int		count;

	count = 0;
	while (nums[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		trimmed = ft_strtrim(nums[i], " \t\n\r");
		if (!trimmed || !trimmed[0])
		{
			if (trimmed)
				free(trimmed);
			i--;
			continue;
		}
		if (!is_valid_number(trimmed))
		{
			free(trimmed);
			free_split(nums);
			free_push_swap(ps);
			print_error();
		}
		num = ft_atoi_safe(trimmed, ps);
		free(trimmed);
		node = create_node(num);
		if (!node)
		{
			free_split(nums);
			free_push_swap(ps);
			print_error();
		}
		push_to_stack(ps->stack_a, node);
		i--;
	}
}

static void	parse_multiple_args(t_push_swap *ps, int argc, char **argv, int start)
{
	int		i;
	int		num;
	t_node	*node;
	char	*trimmed;

	i = argc - 1;
	while (i >= start)
	{
		trimmed = ft_strtrim(argv[i], " \t\n\r");
		if (!trimmed || !trimmed[0])
		{
			if (trimmed)
				free(trimmed);
			i--;
			continue;
		}
		if (!is_valid_number(trimmed))
		{
			free(trimmed);
			free_push_swap(ps);
			print_error();
		}
		num = ft_atoi_safe(trimmed, ps);
		free(trimmed);
		node = create_node(num);
		if (!node)
		{
			free_push_swap(ps);
			print_error();
		}
		push_to_stack(ps->stack_a, node);
		i--;
	}
}

void	parse_args(t_push_swap *ps, int argc, char **argv)
{
	parse_multiple_args(ps, argc, argv, 1);
}

void	parse_args_from_index(t_push_swap *ps, int argc, char **argv, int start)
{
	char	**nums;

	if (argc == start + 1)
	{
		nums = ft_split(argv[start], ' ');
		if (!nums)
		{
			free_push_swap(ps);
			print_error();
		}
		parse_split_args(ps, nums);
		free_split(nums);
	}
	else
	{
		parse_multiple_args(ps, argc, argv, start);
	}
}