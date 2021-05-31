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
		free(info->stack[A]);
		free(info->stack[B]);
		free(info);
		return (0);
	}
	if (init_list_2(info) == 0)
		return (0);
	return (fill_info(info));
}

int		init_list_2(t_info *info)
{
	if (!(info->stack[B]->head = (t_list *)malloc(sizeof(t_list))))
	{
		free(info->stack[A]->head);
		free(info->stack[A]);
		free(info->stack[B]);
		free(info);
	}
	if (!(info->stack[A]->tail = (t_list *)malloc(sizeof(t_list))))
	{
		free_2_list(info->stack[B]->head, info->stack[A]->head);
		free(info->stack[A]);
		free(info->stack[B]);
		free(info);
	}
	if (!(info->stack[B]->tail = (t_list *)malloc(sizeof(t_list))))
	{
		free_3_list(info->stack[A]->tail, info->stack[B]->head,
								info->stack[A]->head);
		free(info->stack[A]);
		free(info->stack[B]);
		free(info);
	}
	else
		return (1);
	return (0);
}
