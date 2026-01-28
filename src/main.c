/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:41:02 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 19:49:58 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_push_swap	*init_push_swap(void)
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

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	if (argc < 2)
		return (0);
	ps = init_push_swap();
	if (!ps)
		print_error();
	parse_args(ps, argc, argv);
	validate_input(ps);
	ft_printf("STACK SIZE = %d\n", ps->stack_a->size);
	if (is_sorted(ps->stack_a))
	{
		free_push_swap(ps);
		return (0);
	}
	assign_indices(ps->stack_a);
	ps->disorder = calculate_disorder(ps->stack_a);
	adaptive_sort(ps);
	free_push_swap(ps);
	return (0);
}