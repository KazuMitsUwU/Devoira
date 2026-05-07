/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:04:53 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/07 09:51:36 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				position;
	int				status;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_bench
{
	float	disorder;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}			t_bench;

typedef struct s_combine
{
	t_bench	*bench;
	t_stack	**stack_a;
	t_stack	**stack_b;
}			t_combine;

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
void	sa(t_combine *c);
void	sb(t_combine *c);
void	ss(t_combine *c);
void	pa(t_combine *c);
void	pb(t_combine *c);
void	ra(t_combine *c);
void	rb(t_combine *c);
void	rr(t_combine *c);
void	rra(t_combine *c);
void	rrb(t_combine *c);
void	rrr(t_combine *c);
void	insertion_sort(t_combine *c);
void	chunk_based_sort(t_combine *c);
void	radix_sort(t_combine *c);
float	disorder_metric(t_stack **stack_a);

#endif
