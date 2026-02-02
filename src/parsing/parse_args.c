/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:19:49 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/02 20:45:49 by aalkhati         ###   ########.fr       */
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

static long	ft_atol(const char *nptr)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + (*nptr - '0');
		nptr++;
	}
	return (number * sign);
}

static void	process_arg(t_push_swap *ps, char *arg)
{
	int		i;
	int		num;
	t_node	*node;

	i = argc - 1;
	while (i >= 1)
	{
		if (!is_valid_number(nums[i]))
		{
			free_split(nums);
			print_error();
		}
		val = ft_atol(nums[i]);
		if (val > 2147483647 || val < -2147483648)
		{
			free_split(nums);
			print_error();
		}
		node = create_node((int)val);
		if (!node)
		{
			free_split(nums);
			print_error();
		}
		push_to_stack(ps->stack_a, node);
		i--;
	}
}

void	parse_args_from_index(t_push_swap *ps, int argc, char **argv, int start)
{
	int		i;
	int		num;
	t_node	*node;

	i = argc - 1;
	while (i >= start)
	{
		if (!is_valid_number(argv[i]))
		{
			free_push_swap(ps);
			print_error();
		}
		num = ft_atoi_safe(argv[i], ps);
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
