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

void	rrab(t_stack *stack)
{
	push_head(stack->tail->prev->data, stack);
	pop_tail(stack);
}

void	rrr(t_stack **stack)
{
	rab(stack[0]);
	rab(stack[1]);
}
