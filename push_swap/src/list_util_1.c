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
	new_list->prev = (t_list *)malloc(sizeof(t_list));
	new_list->next = (t_list *)malloc(sizeof(t_list));
	new_list->data = value;
	new_list->flag = 1;  // node 이다
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
	ft_memset(info->stack[A]->head, 0, sizeof(t_list));
	info->stack[B]->head = (t_list *)malloc(sizeof(t_list));
	ft_memset(info->stack[B]->head, 0, sizeof(t_list));
	info->stack[A]->tail = (t_list *)malloc(sizeof(t_list));
	ft_memset(info->stack[A]->tail, 0, sizeof(t_list));
	info->stack[B]->tail = (t_list *)malloc(sizeof(t_list));
	ft_memset(info->stack[B]->tail, 0, sizeof(t_list));
	if (!info->stack[A] || !info->stack[A] || !info->stack[A] ||!info->stack[A] )
	info->stack[A]->head->next = info->stack[A]->tail;
	info->stack[B]->head->next = info->stack[B]->tail;
	info->stack[A]->tail->prev = info->stack[A]->head;
	info->stack[B]->tail->prev = info->stack[B]->head;
	// info->cmd.head = (t_list *)malloc(sizeof(t_list));
	// info->cmd.head->next = (t_list *)malloc(sizeof(t_list));
	// info->cmd.head->prev = (t_list *)malloc(sizeof(t_list));
	// info->cmd.tail = (t_list *)malloc(sizeof(t_list));
	// info->cmd.tail->next = (t_list *)malloc(sizeof(t_list));
	// info->cmd.tail->prev = (t_list *)malloc(sizeof(t_list));
	// info->cmd.head->next = info->cmd.tail;
	// info->cmd.head->prev = NULL;
	// info->cmd.tail->prev = info->cmd.head;
	// info->cmd.tail->next = NULL;
	// info->cmd.head->flag = 0;  //node 가 아니고 head 나 tail 이다!
	// info->cmd.tail->flag = 0;
}

// void	init_arr(t_box *box, int len)
// {
// 	int	*tmp;

// 	tmp = box->arr;
// 	quicksort(tmp, 0, len -1);
// 	box->min = tmp[len - 1];
// 	box->max = tmp[0];
// 	box->pivot2 = tmp[2 * len / 3];
// 	box->pivot1 = tmp[len / 3];
// }

int		*find_pivot(t_info *info, int num, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;
	int		*pivot;

	i = -1;
	pivot = malloc(2 * sizeof(int));
	now = info->stack[num]->head->next;
	while (++i < r)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	pivot[1] = tmp_arr[2 * r / 3];
	pivot[0] = tmp_arr[r / 3];
	return (pivot);
}

int		check_sorted_a(t_info *info, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;

	i = -1;
	now = info->stack[A]->head->next;
	while (++i < r)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	i = -1;
	now = info->stack[A]->head->next;
	while (++i < r)
	{
		if (tmp_arr[i] != now->data)
			return (0);
		now = now->next;
	}
	return (1);
}

int		check_sorted_b(t_info *info, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;

	i = -1;
	now = info->stack[B]->head->next;
	while (++i < r)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	i = -1;
	now = info->stack[B]->tail->prev;
	while (++i < r)
	{
		if (tmp_arr[i] != now->data)
			return (0);
		now = now->prev;
	}
	return (1);
}
