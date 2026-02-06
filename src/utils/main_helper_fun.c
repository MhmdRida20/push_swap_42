/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:34:53 by mrida             #+#    #+#             */
/*   Updated: 2026/02/06 16:21:31 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_flag(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-')
		return (1);
	return (0);
}

int	ft_strcmp_simple(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_benchmark(t_push_swap *ps, int bench_mode)
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

void	run_sort(t_push_swap *ps)
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
