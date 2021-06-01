/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:03:26 by najlee            #+#    #+#             */
/*   Updated: 2021/06/01 17:20:59 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	classification_b(t_info *info, int r, int pivot[], t_idx *idx)
{
	int tmp;

	while (r--)
	{
		tmp = info->stack[B]->head->next->data;
		if (tmp < pivot[0])
		{
			push_tail_rb(info);
			idx->rb++;
		}
		else
		{
			push_tail_pa(info);
			idx->pa++;
			if (tmp < pivot[1] && info->stack[A]->size > 1)
			{
				push_tail_ra(info);
				idx->ra++;
			}
			else if (tmp < pivot[1])
				idx->ra++;
		}
	}
}

void	optimization_bb(t_idx *idx, t_info *info)
{
	int i;

	i = -1;
	while (++i < min(idx->ra, idx->rb))
	{
		push_tail(RRR, &info->cmd);
		rrr(info);
	}
	i = -1;
	if (idx->rb > idx->ra)
	{
		while (++i < (idx->rb - idx->ra))
			push_tail_rrb(info);
	}
	else
	{
		while (++i < (idx->ra - idx->rb))
			push_tail_rra(info);
	}
}

void	optimization_b(t_idx *idx, t_info *info)
{
	int i;

	if (idx->ra == info->stack[A]->size)
		idx->ra = 0;
	if (idx->rb == info->stack[B]->size)
		idx->rb = 0;
	if ((info->stack[A]->size - idx->ra) < idx->ra)
	{
		if ((idx->rb + info->stack[A]->size - idx->ra) < max(idx->rb, idx->ra))
		{
			idx->ra = info->stack[A]->size - idx->ra;
			i = -1;
			while (++i < idx->rb)
				push_tail_rrb(info);
			i = -1;
			while (++i < idx->ra)
				push_tail_ra(info);
		}
	}
	else
		optimization_bb(idx, info);
}
