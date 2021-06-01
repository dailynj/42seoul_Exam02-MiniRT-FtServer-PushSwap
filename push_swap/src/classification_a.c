/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:03:26 by najlee            #+#    #+#             */
/*   Updated: 2021/06/01 17:20:02 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	classification_a(t_info *info, int r, int pivot[], t_idx *idx)
{
	while (r--)
	{
		if (info->stack[A]->head->next->data >= pivot[1])
		{
			push_tail_ra(info);
			idx->ra++;
		}
		else
		{
			push_tail_pb(info);
			idx->pb++;
			if (info->stack[B]->head->next->data >= pivot[0]
									&& info->stack[B]->size > 1)
			{
				push_tail_rb(info);
				idx->rb++;
			}
			else if (info->stack[B]->head->next->data >= pivot[0])
				idx->rb++;
		}
	}
}

void	optimization_aa(t_idx *idx, t_info *info)
{
	int i;

	i = -1;
	while (++i < min(idx->ra, idx->rb))
	{
		push_tail(RRR, &info->cmd);
		rrr(info);
	}
	i = -1;
	if (idx->ra > idx->rb)
	{
		while (++i < (idx->ra - idx->rb))
			push_tail_rra(info);
	}
	else
	{
		while (++i < (idx->rb - idx->ra))
			push_tail_rrb(info);
	}
}

void	optimization_a(t_idx *idx, t_info *info)
{
	int i;

	if (idx->ra == info->stack[A]->size)
		idx->ra = 0;
	if (idx->rb == info->stack[B]->size)
		idx->rb = 0;
	if ((info->stack[B]->size - idx->rb) < idx->rb)
	{
		if ((idx->ra + info->stack[B]->size - idx->rb) < max(idx->ra, idx->rb))
		{
			idx->rb = info->stack[B]->size - idx->rb;
			i = -1;
			while (++i < idx->ra)
				push_tail_rra(info);
			i = -1;
			while (++i < idx->rb)
				push_tail_rb(info);
		}
	}
	else
		optimization_aa(idx, info);
}
