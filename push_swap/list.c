#include "push_swap.h"

void init_list(t_info *info)
{
	info->stack[A]->size = 0;
	info->stack[B]->size = 0;
	info->stack[A]->head = (t_list *)malloc(sizeof(t_list));
	info->stack[A]->head->next = info->stack[A]->tail;
	info->stack[B]->head = (t_list *)malloc(sizeof(t_list));
	info->stack[B]->head->next = info->stack[B]->tail;
	info->stack[A]->tail = (t_list *)malloc(sizeof(t_list));
	info->stack[A]->tail->prev = info->stack[A]->head;
	info->stack[B]->tail = (t_list *)malloc(sizeof(t_list));
	info->stack[B]->tail->prev = info->stack[B]->head;
}

void add_head(int value, t_stack *stack)
{
	t_list *new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	new_list->data = value;
	new_list->prev = stack->head;
	new_list->next = stack->head->next;
	stack->head->next->prev = new_list;
	stack->head->next = new_list;
}

void add_tail(int value, t_stack *stack)
{
	t_list *new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	new_list->data = value;
	new_list->prev = stack->tail->prev;
	new_list->next = stack->tail;
	stack->tail->prev->next = new_list;
	stack->tail->prev = new_list;
}