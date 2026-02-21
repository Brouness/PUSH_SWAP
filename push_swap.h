#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct push_swap
{
	int					data;//array to store elements
	int					capacity;//maximum size of Stack
	int					top;//index of the top element
	struct push_swap	*next; 
}	Stack;

Stack	*ft_Stack_creation(int capacity);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
Stack	*ft_new_list(int data);
void	ft_stack_addback(Stack **one, Stack *last);

#endif