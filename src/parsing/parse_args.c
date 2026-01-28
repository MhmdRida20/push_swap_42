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
