/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:58:22 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/03 13:28:07 by mrida            ###   ########.fr       */
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

static int	is_flag(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-')
		return (1);
	return (0);
}

static int	ft_strcmp_simple(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	parse_flags(t_push_swap *ps,
	int argc, char **argv, int *start, int *bench)
{
	int	i;

	*bench = 0;
	*start = 1;
	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		if (ft_strcmp_simple(argv[i], "--bench") == 0)
			*bench = 1;
		else if (ft_strcmp_simple(argv[i], "--simple") == 0)
			ps->strategy = SIMPLE;
		else if (ft_strcmp_simple(argv[i], "--medium") == 0)
			ps->strategy = MEDIUM;
		else if (ft_strcmp_simple(argv[i], "--complex") == 0)
			ps->strategy = COMPLEX;
		i++;
	}
	*start = i;
}

static void	run_sort(t_push_swap *ps)
{
	if (ps->strategy == SIMPLE)
		simple_sort(ps);
	else if (ps->strategy == MEDIUM)
		medium_sort(ps);
	else if (ps->strategy == COMPLEX)
		complex_sort(ps);
	else
		adaptive_sort(ps);
}

static void	print_benchmark(t_push_swap *ps, int bench_mode)
{
	if (!bench_mode)
		return ;
	ft_printf("\n========== BENCHMARK ==========\n");
	ft_printf("Stack size:     %d\n", ps->stack_a->size + ps->stack_b->size);
	ft_printf("Disorder:       %d%%\n", (int)(ps->disorder * 100));
	ft_printf("Strategy:       ");
	if (ps->strategy == SIMPLE)
		ft_printf("SIMPLE\n");
	else if (ps->strategy == MEDIUM)
		ft_printf("MEDIUM\n");
	else if (ps->strategy == COMPLEX)
		ft_printf("COMPLEX\n");
	else
		ft_printf("ADAPTIVE\n");
	ft_printf("Operations:     %d\n", ps->op_count);
	ft_printf("===============================\n");
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			start;
	int			bench_mode;

	if (argc < 2)
		return (0);
	ps = init_push_swap();
	if (!ps)
		print_error();
	parse_flags(ps, argc, argv, &start, &bench_mode);
	if (start >= argc)
	{
		free_push_swap(ps);
		return (0);
	}
	parse_args_from_index(ps, argc, argv, start);
	validate_input(ps);
	if (is_sorted(ps->stack_a))
	{
		free_push_swap(ps);
		return (0);
	}
	assign_indices(ps->stack_a);
	ps->disorder = calculate_disorder(ps->stack_a);
	run_sort(ps);
	print_benchmark(ps, bench_mode);
	free_push_swap(ps);
	return (0);
}
