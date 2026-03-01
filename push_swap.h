/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:19:55 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 23:42:06 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct t_push_swap
{
	int					data;
	int					idx;
	int					pos;
	int					total_cost;
	int					cost_a;
	int					cost_b;
	struct t_push_swap	*target;
	struct t_push_swap	*next;
}	t_Stack;
// linked list functions
t_Stack	*ft_new_list(int data);
void	ft_stack_addback(t_Stack **one, t_Stack *last);
void	ft_add_front(t_Stack **a, t_Stack *b);
int		ft_lst_size(t_Stack *a);
void	ft_free_stack(t_Stack *a);
// push_swap helper functions
void	ft_push_swap(t_Stack **a, t_Stack **b);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_sort_five(t_Stack **a, t_Stack **b);
void	ft_sort_four(t_Stack **a, t_Stack **b);
void	ft_sort_three(t_Stack **a);
void	ft_sort_two(t_Stack **a);
void	apply_algorithm(t_Stack **a, t_Stack **b);
void	initialise_stack_pos(t_Stack **a);
// push_swap algorithme
void	stack_indexing(t_Stack **a);
t_Stack	*min_node(t_Stack *a);
t_Stack	*find_target_node(t_Stack **a, t_Stack **b);
void	cost_calculation(t_Stack **a, t_Stack **b, t_Stack **b_node);
void	apply_algorithm(t_Stack **a, t_Stack **b);
int		abs(int x);
int		max(int a, int b);
t_Stack	*find_cheapest(t_Stack **b);
void	final_rotation(t_Stack **a);
// push_swap operations functions
void	sa(t_Stack **a);
void	sb(t_Stack **b);
void	ss(t_Stack **a, t_Stack **b);
void	pa(t_Stack **a, t_Stack **b);
void	pb(t_Stack **b, t_Stack **a);
void	ra(t_Stack **a);
void	rb(t_Stack **b);
void	rr(t_Stack **a, t_Stack **b);
void	rra(t_Stack **a);
void	rrb(t_Stack **b);
void	rrr(t_Stack **a, t_Stack **b);
void	swap(t_Stack **stack);
void	reverce_rotate(t_Stack **stack);
void	reverce(t_Stack **stack);
void	exec(t_Stack **a, t_Stack **b, t_Stack *cheapt);
void	rot_smaller(t_Stack **a);

#endif