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

	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new_list->prev = prev;
	new_list->next = next;
	new_list->data = value;
	new_list->flag = 1;
	return (new_list);
}

int		fill_info(t_info *info)
{
	info->stack[A]->size = 0;
	info->stack[B]->size = 0;
	ft_memset(info->stack[A]->head, 0, sizeof(t_list));
	ft_memset(info->stack[B]->head, 0, sizeof(t_list));
	ft_memset(info->stack[A]->tail, 0, sizeof(t_list));
	ft_memset(info->stack[B]->tail, 0, sizeof(t_list));
	info->stack[A]->head->next = info->stack[A]->tail;
	info->stack[B]->head->next = info->stack[B]->tail;
	info->stack[A]->tail->prev = info->stack[A]->head;
	info->stack[B]->tail->prev = info->stack[B]->head;
	return (init_cmd(info));
}

int		init_list_2(t_info *info)
{
	if (!(info->stack[B]->head = (t_list *)malloc(sizeof(t_list))))
	{
		free(info->stack[A]->head);
		free_2_stack(info->stack[A], info->stack[B]);
		free(info);
		return (0);
	}
	if (!(info->stack[A]->tail = (t_list *)malloc(sizeof(t_list))))
	{
		free_2_list(info->stack[B]->head, info->stack[A]->head);
		free_2_stack(info->stack[A], info->stack[B]);
		free(info);
		return (0);
	}
	if (!(info->stack[B]->tail = (t_list *)malloc(sizeof(t_list))))
	{
		free_3_list(info->stack[A]->tail, info->stack[B]->head,
							info->stack[A]->head);
		free_2_stack(info->stack[A], info->stack[B]);
		free(info);
		return (0);
	}
	return (1);
}

int		init_list(t_info *info)
{
	if (!(info->stack[A] = (t_stack *)malloc(sizeof(t_stack))))
	{
		free(info);
		return (0);
	}
	if (!(info->stack[B] = (t_stack *)malloc(sizeof(t_stack))))
	{
		free(info->stack[A]);
		free(info);
		return (0);
	}
	if (!(info->stack[A]->head = (t_list *)malloc(sizeof(t_list))))
	{
		free_2_stack(info->stack[A], info->stack[B]);
		free(info);
		return (0);
	}
	if (!init_list_2(info))
		return (0);
	return (fill_info(info));
}

int		*find_pivot(t_info *info, int num, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;
	int		*pivot;

	i = -1;
	pivot = malloc(2 * sizeof(int));
	now = info->stack[num]->head->next;
	while (++i < r && now->flag)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	pivot[1] = tmp_arr[2 * r / 3];
	pivot[0] = tmp_arr[r / 3];
	return (pivot);
}
