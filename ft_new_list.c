/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:15:00 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/20 10:08:17 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	*ft_new_list(int data)
{
	Stack	*a;

	a = malloc(sizeof(Stack));
	a->data = data;
	a->next = NULL;
	return (a);
}