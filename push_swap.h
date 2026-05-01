/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:43:33 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/01 14:06:24 by sitrakaa         ###   ########.fr       */
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
int		*make_temp_arr(t_stack **stack_a, int size);
void	sort_arr(int *temp_arr, int size);
void	define_positions(t_stack **stack_a, int *temp_arr, int size);
int		get_min(t_stack *stack_a);
int		get_max_position(t_stack **stack_b);
int		ft_sqrt(int size);
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
void	insertion_sort(t_stack **stack_a, t_stack **stack_b);
void	chunk_based_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		disorder_metric(t_stack **stack_a);

#endif
