#include "push_swap.h"

void sab(t_stack *stack)
{
	t_list *tmp;
	
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp = stack->head->next->next;
	stack->head->next->next = stack->head->next;
	stack->head->next = stack->head->next->next;
	free(tmp);
}

void ss(t_stack **stack)
{
	sab(stack[0]);
	sab(stack[1]);
}

void pab(t_stack **stack, int n)
{
	push_head(stack[!n]->head->next->data, stack[n]);
	pop_head(stack[!n]);
}

void rab(t_stack *stack)
{
	push_tail(stack->head->next, stack);
	pop_head(stack);
}

void rr(t_stack **stack)
{
	rab(stack[0]);
	rab(stack[1]);
}