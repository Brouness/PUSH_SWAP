/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:08:41 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/20 10:21:49 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_addback(Stack **one, Stack *last)
{
	int	i;
	Stack	*iter;
	iter = *one;
	if (!last)
		return ;
	if (!iter)
	{
		*one = last;
		return ;
	}
	i = 0;
	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = last;
}