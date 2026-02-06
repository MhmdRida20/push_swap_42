/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrida <mrida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:38:28 by aalkhati          #+#    #+#             */
/*   Updated: 2026/02/06 16:21:58 by mrida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/// @brief to update
/// @param ps 
/* Custom adaptive algorithm (learner’s design): Design an adaptive strategy
that selects different internal methods depending on the measured disorder. You
are not constrained to any specific named algorithm; the internal techniques are
entirely up to you. 
However, your design must respect the following complexity
targets per regime (in the Push_swap operation model):
- Low disorder: if disorder < 0.2, your chosen method must run in O(n) time.
- Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in
O(n
√
n) time.
- High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n)
time.*/
double	compute_disorder(t_stack *pa)
{
	int		mistakes;
	int		total_pair;
	t_node	*node_a;
	t_node	*node_b;

	if (!pa || pa->size)
		return (0.0);
	mistakes = 0;
	total_pair = 0;
	node_a = pa->top;
	while (node_a)
	{
		node_b = node_a->next;
		while (node_b)
		{
			total_pair++;
			if (node_a->value > node_b->value)
				mistakes++;
			node_b = node_b->next;
		}
		node_a = node_a->next;
		if (total_pair == 0)
			return (0.0);
	}
	return ((double)mistakes / (double)total_pair);
}

void	adaptive_sort(t_push_swap *ps)
{
	int		size;
	double	disorder;

	disorder = compute_disorder(ps->stack_a);
	ps->disorder = disorder;
	if (!ps || !ps->stack_a)
		return ;
	size = ps->stack_a->size;
	if (size <= 1)
		return ;
	else if (disorder < 0.2)
	{
		simple_sort(ps);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
		medium_sort(ps);
	else
		complex_sort(ps);
}
