/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:11:57 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:11:58 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*node(int value, t_list *prev, t_list *next)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	new_list->data = value;
	new_list->prev = prev;
	new_list->next = next;
	return (new_list);
}

void	init_list(t_info *info)
{
	info->stack[A] = (t_stack *)malloc(sizeof(t_stack));
	info->stack[B] = (t_stack *)malloc(sizeof(t_stack));
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
