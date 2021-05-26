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

void	sab(t_stack *stack)
{
	int tmp1;
	int tmp2;

	tmp1 = stack->head->next->data;
	pop_head(stack);
	tmp2 = stack->head->next->data;
	pop_head(stack);
	push_head(tmp1, stack);
	push_head(tmp2, stack);
}

void	ss(t_stack **stack)
{
	if (stack[A]->size > 0)
		sab(stack[A]);
	if (stack[B]->size > 0)
		sab(stack[B]);
}

void	pab(t_stack **stack, int n)
{
	push_head(stack[!n]->head->next->data, stack[n]);
	pop_head(stack[!n]);
}

void	rab(t_stack *stack)
{
	push_tail(stack->head->next->data, stack);
	pop_head(stack);
}

void	rr(t_stack **stack)
{
	if (stack[A]->size > 0)
		rab(stack[A]);
	if (stack[B]->size > 0)
		rab(stack[B]);
}
