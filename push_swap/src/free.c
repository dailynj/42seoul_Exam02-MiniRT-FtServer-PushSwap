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
	//////////// free info 모두 하기
	free(info);
}

void	free_stack(t_stack *stack)
{
	free(stack->head);
	free(stack->tail);
	free(stack);
}
