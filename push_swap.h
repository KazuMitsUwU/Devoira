/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:43:33 by manoaran          #+#    #+#             */
/*   Updated: 2026/04/30 16:59:14 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				position;
	int				status;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int		nb_of_layer(t_stack **stack);
void	add_on_top(t_stack **stack, int value);
void	add_at_bot(t_stack **stack, int value);
void	stack_a_init(t_stack **stack_a, int argc, char **argv);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	medium_sort(t_stack **stack_a, t_stack **stack_b);
int		get_max_position(t_stack **stack_b);
int		get_min(t_stack *stack_a);
int		disorder_metric(t_stack **stack_a);

#endif