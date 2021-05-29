/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:01:46 by najlee            #+#    #+#             */
/*   Updated: 2021/05/28 18:01:47 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_box(t_box *box)
{
	free(box->arr);
	free(box);
}

void	free_info(t_info *info)
{
	free(info->stack[A]->tail);
	free(info->stack[B]->tail);
	free(info->stack[B]->head);
	free(info->stack[A]->head);
	free(info->stack[A]);
	free(info->stack[B]);
	free(info);
}

void	free_stack(t_stack *stack)
{
	free(stack->head);
	free(stack->tail);
	free(stack);
}

void	free_two_list(t_info *info)
{
	t_list *now;

	now = info->stack[A]->head->next;
	while (now->flag)
	{
		now = now->next;
		free(now->prev);
	}
	now = info->stack[B]->head->next;
	while (now->flag)
	{
		now = now->next;
		free(now->prev);
	}
}
