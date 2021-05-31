/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:39:13 by najlee            #+#    #+#             */
/*   Updated: 2021/05/31 15:39:14 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	classification_ab(t_info *info, int r, int pivot[], t_idx *idx)
{
	while (r--)
	{
		if (info->stack[A]->head->next->data >= pivot[1])
		{
			push_tail(RA, &info->cmd);
			rab(info, A);
			idx->ra++;
		}
		else
		{
			push_tail(PB, &info->cmd);
			pab(info, B);
			idx->pb++;
			if (info->stack[B]->head->next->data >= pivot[0] &&
												info->stack[B]->size > 1)
			{
				push_tail(RB, &info->cmd);
				rab(info, B);
				idx->rb++;
			}
			else if (info->stack[B]->head->next->data >= pivot[0])
				idx->rb++;
		}
	}
}

void	classification_ba(t_info *info, int r, int pivot[], t_idx *idx)
{
	while (r--)
	{
		idx->tmp = info->stack[B]->head->next->data;
		if (idx->tmp < pivot[0])
		{
			push_tail(RB, &info->cmd);
			rab(info, B);
			idx->rb++;
		}
		else
		{
			push_tail(PA, &info->cmd);
			pab(info, A);
			idx->pa++;
			if (idx->tmp < pivot[1] && info->stack[A]->size > 1)
			{
				push_tail(RA, &info->cmd);
				rab(info, A);
				idx->ra++;
			}
			else if (idx->tmp < pivot[1])
				idx->ra++;
		}
	}
}
