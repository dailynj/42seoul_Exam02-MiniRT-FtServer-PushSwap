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

void	sab(t_info *info, int num)
{
	int		tmp1;
	int		tmp2;
	t_stack	*stack;

	stack = info->stack[num];
	if (stack->size < 2)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
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
		sab(info, A);
	if (info->stack[B]->size > 0)
		sab(info, B);
}

void	pab(t_info *info, int num)
{
	if (info->stack[!num]->size == 0)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	push_head(info->stack[!num]->head->next->data, info->stack[num]);
	pop_head(info->stack[!num]);
}

void	rab(t_info *info, int num)
{
	t_stack *stack;

	stack = info->stack[num];
	if (stack->size == 0)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	push_tail(stack->head->next->data, stack);
	pop_head(stack);
}

void	rr(t_info *info)
{
	if (info->stack[A]->size > 0)
		rab(info, A);
	if (info->stack[B]->size > 0)
		rab(info, B);
}
