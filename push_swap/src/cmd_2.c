#include "push_swap.h"

void rrab(t_stack *stack)
{
	push_head(stack->tail->prev, stack);
	pop_tail(stack);
}

void rrr(t_stack **stack)
{
	rab(stack[0]);
	rab(stack[1]);
}