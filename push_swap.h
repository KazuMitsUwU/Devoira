/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:43:33 by manoaran          #+#    #+#             */
/*   Updated: 2026/05/18 22:59:10 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_chunk
{
	int	start;
	int	end;
}	t_chunk;

typedef struct s_flags
{
	int	strategy;
	int	bench;
	int	start;
}	t_flags;

# define FLAG_ADAPTIVE  0
# define FLAG_SIMPLE    1
# define FLAG_MEDIUM    2
# define FLAG_COMPLEX   3

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

size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
void	split_and_fill(char **list, int *clean_i, char *string);
char	**make_clean_arg_list(int argc, char **argv);
void	free_clean_arg_list(char **list);
int		is_valid_flag(char *flag);
int		define_clean_argc(char **clean_arg_list);
void	error_exit(char **list, char *msg);
int		my_atoi(const char *arg, char **list);
void	check_flags(int new_argc, char **argv, t_flags *flags);
void	check_int_list(char **clean_arg_list, int start);
void	parsing(int argc, char **argv, t_stack **stack_a, t_flags *flags);
void	check_if_sorted(t_stack **stack_a);
int		nb_of_layer(t_stack **stack);
void	find_flag(char *arg, t_flags *flags, int *counts, char **list);
void	add_on_top(t_stack **stack, int value);
void	add_at_bot(t_stack **stack, int value);
void	free_stack(t_stack **stack);
int		get_min_value(t_stack *stack_a);
int		get_lowest_position(t_stack **stack_b);
int		*make_temp_arr(t_stack **stack_a, int size);
void	sort_arr(int *temp_arr, int size);
void	define_positions(t_stack **stack_a, int *temp_arr, int size);
int		ft_sqrt(int size);
void	print_op(char *op);
void	print_bench(t_bench *bench, int flag);
void	sa(t_stack **stack_a, t_bench *bench);
void	sb(t_stack **stack_b, t_bench *bench);
void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	ra(t_stack **stack_a, t_bench *bench);
void	rb(t_stack **stack_b, t_bench *bench);
void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	rra(t_stack **stack_a, t_bench *bench);
void	rrb(t_stack **stack_b, t_bench *bench);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
float	disorder_metric(t_stack **stack_a);
void	sort_small(t_stack **a, t_bench *bench);
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	process_chunk(t_stack **stack_a, t_stack **stack_b,
			t_chunk chunk, t_bench *bench);
void	chunk_push(t_stack **stack_a, t_stack **stack_b,
			int size, t_bench *bench);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);
void	three_five_sort(t_stack **a, t_stack **b, t_bench *bench);
int		stack_size(t_stack *stack);
int		find_min(t_stack **a);
void	push_two_min(t_stack **a, t_stack **b, t_bench *bench);

#endif
