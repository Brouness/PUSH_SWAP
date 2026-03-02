/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:54:28 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 15:45:11 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

static int	execute_moves(char *line, t_Stack **a, t_Stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static void	error(t_Stack **a, t_Stack **b)
{
	ft_free_stack(*a);
	ft_free_stack(*b);
	write(2, "Error\n", 6);
}

static int	is_sorted(t_Stack *a)
{
	t_Stack	*tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_Stack	*a;
	t_Stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!handle_arguments(&a, av))
		return (ft_free_stack(a), write(2, "Error\n", 6), 0);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!execute_moves(line, &a, &b))
			return (free(line), error(&a, &b), 0);
		free(line);
	}
	free(line);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_free_stack(a), ft_free_stack(b), 0);
}
