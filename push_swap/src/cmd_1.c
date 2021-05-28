/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:09:48 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:09:49 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sab(t_info *info, int num, int flag)
{
	int		tmp1;
	int		tmp2;
	t_stack	*stack;
	(void) flag;
	
	stack = info->stack[num];
	if (stack->size < 2)
		return ;
	tmp1 = stack->head->next->data;
	pop_head(stack);
	tmp2 = stack->head->next->data;
	pop_head(stack);
	push_head(tmp1, stack);
	push_head(tmp2, stack);
}

void	ss(t_info *info)
{
	if (info->stack[A]->size > 0)
		sab(info, A, 0);
	if (info->stack[B]->size > 0)
		sab(info, B, 0);
}

void	pab(t_info *info, int num)
{
	if (info->stack[!num]->size == 0)
		return ;
	push_head(info->stack[!num]->head->next->data, info->stack[num]);
	pop_head(info->stack[!num]);
}

void	rab(t_info *info, int num, int flag)
{
	t_stack *stack;
	(void) flag;
	stack = info->stack[num];
	if (stack->size == 0)
		return ;
	push_tail(stack->head->next->data, stack);
	pop_head(stack);
}

void	rr(t_info *info)
{
	if (info->stack[A]->size > 0)
		rab(info, A, 0);
	if (info->stack[B]->size > 0)
		rab(info, B, 0);
}
