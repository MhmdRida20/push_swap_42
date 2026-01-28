/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:19:49 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 19:51:06 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	parse_split(t_push_swap *ps, char *arg)
{
	char	**nums;
	int		i;
	t_node	*node;

	nums = ft_split(arg, ' ');
	if (!nums)
		print_error();

	i = 0;
	while (nums[i])
		i--;

	while (++i >= 0 && nums[i])
	{
		node = create_node(ft_atoi(nums[i]));
		if (!node)
		{
			free_split(nums);
			print_error();
		}
		push_to_stack(ps->stack_a, node);
		i--;
	}
	free_split(nums);
}

void	parse_args(t_push_swap *ps, int argc, char **argv)
{
	int		i;
	t_node	*node;

	if (argc == 2)
	{
		parse_split(ps, argv[1]);
		return ;
	}
	i = argc - 1;
	while (i >= 1)
	{
		node = create_node(ft_atoi(argv[i]));
		if (!node)
			print_error();
		push_to_stack(ps->stack_a, node);
		i--;
	}
}


