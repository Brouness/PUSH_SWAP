/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:54:28 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 16:59:20 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_stack(t_Stack **stack)
{
	t_Stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

static void error_exit(t_Stack **a, t_Stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_Stack *a;
	t_Stack *b;
	char    *line;

	a = NULL;
	b = NULL;

	if (ac < 2)
		return (0);

	if (!handle_arguments(&a, av))
	{
			return (ft_free_stack(a), write(1, "Error\n", 6), 0);
	}
	stack_indexing(&a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (!execute_instruction(line, &a, &b))
		{
			free(line);
			error_exit(&a, &b);
		}
		free(line);
	}

	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	free_stack(&a);
	return (0);
}
