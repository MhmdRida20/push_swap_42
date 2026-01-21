/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:19:49 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/21 20:14:55 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	parse_args(t_push_swap *ps, int argc, char **argv)
{
	int		i;
	int		num;
	t_node	*node;

	i = argc - 1;
	while (i >= 1)
	{
		num = ft_atoi(argv[i]);
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
