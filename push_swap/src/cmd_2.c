/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:11:18 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:11:19 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrab(t_info *info, int num, int flag)
{
	t_stack *stack;
	(void) flag;
	stack = info->stack[num];
	if (stack->size == 0)
		return ;
	push_head(stack->tail->prev->data, stack);
	pop_tail(stack);
}

void	rrr(t_info *info)
{
	if (info->stack[A]->size > 0)
		rrab(info, A, 0);
	if (info->stack[B]->size > 0)
		rrab(info, B, 0);
}
