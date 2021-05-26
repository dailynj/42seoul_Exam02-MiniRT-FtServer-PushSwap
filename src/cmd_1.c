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
	if (stack->size == 0)
	{
		printf("sab error\n");
		return ;
	}
	tmp1 = stack->head->next->data;
	pop_head(stack);
	tmp2 = stack->head->next->data;
	pop_head(stack);
	push_head(tmp1, stack);
	push_head(tmp2, stack);
	// if (num == 0)
	// 	push_tail(SA, &(info->cmd));
	// else
	// 	push_tail(SB, &(info->cmd));
	if (num == 0)
		printf("sa\n");
	else
		printf("sb\n");
}

void	ss(t_info *info)
{
	if (info->stack[A]->size > 0)
		sab(info, A);
	if (info->stack[B]->size > 0)
		sab(info, B);
	// push_tail(SS, &(info->cmd));
	printf("ss\n");
}

void	pab(t_info *info, int num)
{
	if (info->stack[!num]->size == 0)
	{
		printf("pab error\n");
		return ;
	}
	push_head(info->stack[!num]->head->next->data, info->stack[num]);
	pop_head(info->stack[!num]);
	// if (num == 0)
	// 	push_tail(PA, &(info->cmd));
	// else
	// 	push_tail(PB, &(info->cmd));
	if (num == 0)
		printf("pa\n");
	else
		printf("pb\n");
}

void	rab(t_info *info, int num)
{
	t_stack *stack;
	
	stack = info->stack[num];
	if (stack->size == 0)
	{
		printf("rab error\n");
		return ;
	}
	push_tail(stack->head->next->data, stack);
	pop_head(stack);
	// if (num == 0)
	// 	push_tail(RA, &(info->cmd));
	// else
	// 	push_tail(RB, &(info->cmd));
	if (num == 0)
		printf("ra\n");
	else
		printf("rb\n");
}

void	rr(t_info *info)
{
	if (info->stack[A]->size > 0)
		rab(info, A);
	if (info->stack[B]->size > 0)
		rab(info, B);
	// push_tail(RR, &(info->cmd));
	printf("rr\n");
}
