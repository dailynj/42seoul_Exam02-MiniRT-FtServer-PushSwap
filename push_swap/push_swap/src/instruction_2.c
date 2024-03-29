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

void	rrab(t_info *info, int num)
{
	t_stack *stack;

	stack = info->stack[num];
	if (stack->size == 0)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	push_head(stack->tail->prev->data, stack);
	pop_tail(stack);
}

void	rrr(t_info *info)
{
	if (info->stack[A]->size > 0)
		rrab(info, A);
	if (info->stack[B]->size > 0)
		rrab(info, B);
}
