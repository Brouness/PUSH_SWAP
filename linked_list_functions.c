/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:36:33 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/27 15:20:34 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*ft_new_list(int data)
{
	t_Stack	*a;

	a = malloc(sizeof(t_Stack));
	if (!a)
		return (NULL);
	a->data = data;
	a->next = NULL;
	return (a);
}

void	ft_stack_addback(t_Stack **one, t_Stack *last)
{
	t_Stack	*iter;

	iter = *one;
	if (!last)
		return ;
	if (!iter)
	{
		*one = last;
		return ;
	}
	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = last;
}

void	ft_free_stack(t_Stack *a)
{
	t_Stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

int	ft_lst_size(t_Stack *a)
{
	t_Stack	*tmp;
	int		size;

	size = 0;
	tmp = a;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	ft_add_front(t_Stack **a, t_Stack *b)
{
	if (!b)
		return ;
	if (!*a)
	{
		*a = b;
		return ;
	}
	b->next = *a;
	*a = b;
}
// int main()
// {
// 	int i = 0;
// 	t_Stack	*b;
// 	b = NULL;
// 	while (i < 5)
// 	{
// 		ft_t_Stack_addback(&b, ft_new_list(i));
// 		i++;
// 	}
// 	i = 0;
// 	i = ft_lst_size(b);
// 	printf("this is the size of lst : %d\n", i);
// 	t_Stack *f;
// 	while (b)
// 	{
// 		f = b;
// 		printf("this is the first node element : %d\n", b->data);
// 		b = b->next;
// 		free(f);
// 	}
// }