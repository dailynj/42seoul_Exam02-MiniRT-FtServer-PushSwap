#include "push_swap.h"

void sab(t_stack *stack)
{
	t_list *tmp;
	
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp = stack->head->next;
	stack->head->next = stack->head;
	stack->head = stack->head->next;
	free(tmp);
}

void ss(t_stack **stack)
{
	sab(stack[0]);
	sab(stack[1]);
}