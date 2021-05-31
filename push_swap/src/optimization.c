/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:39:22 by najlee            #+#    #+#             */
/*   Updated: 2021/05/31 15:39:23 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	optimization_ab_2(t_idx *idx, t_info *info)
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
		{
			push_tail(RRA, &info->cmd);
			rrab(info, A);
		}
	}
	else
	{
		while (++i < (idx->rb - idx->ra))
		{
			push_tail(RRB, &info->cmd);
			rrab(info, B);
		}
	}
}

void	optimization_ab(t_idx *idx, t_info *info, int i)
{
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
			{
				push_tail(RRA, &info->cmd);
				rrab(info, A);
			}
			i = -1;
			while (++i < idx->rb)
			{
				push_tail(RB, &info->cmd);
				rab(info, B);
			}
		}
	}
	else
		optimization_ab_2(idx, info);
}

void	optimization_ba_2(t_idx *idx, t_info *info)
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
		{
			push_tail(RRB, &info->cmd);
			rrab(info, B);
		}
	}
	else
	{
		while (++i < (idx->ra - idx->rb))
		{
			push_tail(RRA, &info->cmd);
			rrab(info, A);
		}
	}
}

void	optimization_ba(t_idx *idx, t_info *info, int i)
{
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
			{
				push_tail(RRB, &info->cmd);
				rrab(info, B);
			}
			i = -1;
			while (++i < idx->ra)
			{
				push_tail(RA, &info->cmd);
				rab(info, A);
			}
		}
	}
	else
		optimization_ba_2(idx, info);
}
