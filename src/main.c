/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:58:22 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/06 16:21:08 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handle_strategy_flag(t_push_swap *ps, char *flag, int *bench)
{
	if (ft_strcmp_simple(flag, "--bench") == 0)
		*bench = 1;
	else if (ft_strcmp_simple(flag, "--simple") == 0)
		ps->strategy = SIMPLE;
	else if (ft_strcmp_simple(flag, "--medium") == 0)
		ps->strategy = MEDIUM;
	else if (ft_strcmp_simple(flag, "--complex") == 0)
		ps->strategy = COMPLEX;
	else if (ft_strcmp_simple(flag, "--adaptive") == 0)
		ps->strategy = ADAPTIVE;
}

static int	parse_flags(t_push_swap *ps, int argc, char **argv, int *bench)
{
	int	i;

	*bench = 0;
	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		handle_strategy_flag(ps, argv[i], bench);
		i++;
	}
	return (i);
}

static void	perform_sort(t_push_swap *ps)
{
	assign_indices(ps->stack_a);
	ps->disorder = compute_disorder(ps->stack_a);
	run_sort(ps);
}

static int	parse_and_check(t_push_swap *ps, int argc, char **argv, int *bench)
{
	int	start;

	start = parse_flags(ps, argc, argv, bench);
	if (start >= argc)
		return (0);
	parse_args_from_index(ps, argc, argv, start);
	validate_input(ps);
	if (is_sorted(ps->stack_a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			bench;

	if (argc < 2)
		return (0);
	ps = init_push_swap();
	if (!ps)
		print_error();
	if (parse_and_check(ps, argc, argv, &bench))
	{
		perform_sort(ps);
		print_benchmark(ps, bench);
	}
	free_push_swap(ps);
	return (0);
}
