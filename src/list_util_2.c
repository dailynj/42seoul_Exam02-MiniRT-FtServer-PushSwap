/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:12:04 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:12:05 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_all(t_stack *stack, long long arr[], int len)
{
	int idx;

	idx = -1;
	while (++idx < len)
		push_head(arr[idx], stack);
}

void	push_head(int value, t_stack *stack)
{
	t_list *new_list;

	new_list = node(value, stack->head, stack->head->next);
	stack->head->next->prev = new_list;
	stack->head->next = new_list;
	stack->size++;
}

void	push_tail(int value, t_stack *stack)
{
	t_list *new_list;

	new_list = node(value, stack->tail->prev, stack->tail);
	stack->tail->prev->next = new_list;
	stack->tail->prev = new_list;
	stack->size++;
}

void	pop_head(t_stack *stack)
{
	stack->head->next->next->prev = stack->head;
	stack->head->next = stack->head->next->next;
	stack->size--;
}

void	pop_tail(t_stack *stack)
{
	stack->tail->prev->prev->next = stack->tail;
	stack->tail->prev = stack->tail->prev->prev;
	stack->size--;
}
