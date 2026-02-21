#include "push_swap.h"

void	free_stack(Stack *Stack)
{
	free(Stack);
}

Stack	*ft_Stack_creation(int capacity)
{
	Stack	*a;
	a = malloc(sizeof(Stack));
	if (!a)
	{
		free_stack(a);
		return (NULL);
	}
	a->top = -1;
	a->next = NULL;
	return (a);
}
