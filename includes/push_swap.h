/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:07:34 by aalkhati          #+#    #+#             */
/*   Updated: 2026/01/28 19:52:49 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

//@operation store operations for output
// disorder metric (0-1)
//#strategy which algorithm to use
typedef struct s_push_swap
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			**operations;
	int				op_count;
	double			disorder;
	t_strategy		strategy;
}					t_push_swap;

/* ========== PARSING ========== */
void				parse_args(t_push_swap *ps, int argc, char **argv);
void				validate_input(t_push_swap *ps);

/* ========== STACK INIT ========== */
t_stack				*init_stack(void);
t_node				*create_node(int value);
void				free_stack(t_stack *stack);
void				free_push_swap(t_push_swap *ps);

/* ========== STACK OPERATIONS ========== */
void				push_to_stack(t_stack *stack, t_node *node);
t_node				*detach_top(t_stack *stack);

/* ========== OPERATIONS - SWAP ========== */
void				sa(t_push_swap *ps, int print);
void				sb(t_push_swap *ps, int print);
void				ss(t_push_swap *ps);

/* ========== OPERATIONS - PUSH ========== */
void				pa(t_push_swap *ps);
void				pb(t_push_swap *ps);

/* ========== OPERATIONS - ROTATE ========== */
void				ra(t_push_swap *ps, int print);
void				rb(t_push_swap *ps, int print);
void				rr(t_push_swap *ps);

/* ========== OPERATIONS - REVERSE ========== */
void				rra(t_push_swap *ps, int print);
void				rrb(t_push_swap *ps, int print);
void				rrr(t_push_swap *ps);

/* ========== ALGORITHMS ========== */
void				simple_sort(t_push_swap *ps);
void				medium_sort(t_push_swap *ps);
void				complex_sort(t_push_swap *ps);
void				adaptive_sort(t_push_swap *ps);

/* ========== UTILS ========== */
int					is_sorted(t_stack *stack);
double				calculate_disorder(t_stack *stack);
void				assign_indices(t_stack *stack);
void				print_error(void);
void				free_split(char **split);

#endif