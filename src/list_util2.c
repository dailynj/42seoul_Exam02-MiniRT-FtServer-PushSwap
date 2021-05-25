#include "push_swap.h"

void push_head(int value, t_stack *stack)
{
	t_list *new_list;

	new_list = node(value, stack->head, stack->head->next);
	stack->head->next->prev = new_list;
	stack->head->next = new_list;
	stack->size++;
}

void push_tail(int value, t_stack *stack)
{
	t_list *new_list;

	new_list = node(value, stack->tail->prev, stack->tail);
	stack->tail->prev->next = new_list;
	stack->tail->prev = new_list;
	stack->size++;
}

void pop_head(t_stack *stack)
{
	stack->head->next = stack->head->next->next;
	stack->head->next->next->prev = stack->head;
	stack->size--;
}

void pop_tail(t_stack *stack)
{
	stack->tail->prev = stack->tail->prev->prev;
	stack->tail->prev->prev->next = stack->tail;
	stack->size--;
}