/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:32:32 by najlee            #+#    #+#             */
/*   Updated: 2021/05/26 21:32:33 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_idx(t_idx *idx)
{
	idx->ra = 0;
	idx->rb = 0;
	idx->pa = 0;
	idx->pb = 0;
	idx->sa = 0;
	idx->sb = 0;
	idx->tmp = 0;
}

void	a_to_b(t_info *info, int r)
{
	t_idx	*idx;
	int		i;
	int		*pivot;
	int		tmp[3];

	i = -1;
	if (!(idx = (t_idx *)malloc(sizeof(t_idx))))
		return ;
	init_idx(idx);
	if (r <= 3)
		return (sort_short_a(info, r));
	if (!info->stack[A]->head->next->flag)
		return ;
	pivot = find_pivot(info, A, r);
	classification_ab(info, r, pivot, idx);
	tmp[0] = idx->ra;
	tmp[1] = idx->rb;
	tmp[2] = idx->rb;
	optimization_ab(idx, info, 0);
	free(idx);
	free(pivot);
	a_to_b(info, tmp[0]);
	b_to_a(info, tmp[1]);
	b_to_a(info, tmp[2] - tmp[1]);
}

void	b_to_a(t_info *info, int r)
{
	int		i;
	int		*pivot;
	t_idx	*idx;
	int		tmp[3];

	i = -1;
	if (!(idx = (t_idx *)malloc(sizeof(t_idx))))
		return ;
	init_idx(idx);
	if (r <= 3)
		return (sort_short_b(info, r));
	if (!info->stack[B]->head->next->flag)
		return ;
	pivot = find_pivot(info, B, r);
	classification_ba(info, r, pivot, idx);
	free(pivot);
	tmp[0] = idx->pa;
	tmp[1] = idx->ra;
	tmp[2] = idx->pb;
	free(idx);
	a_to_b(info, tmp[0] - tmp[1]);
	optimization_ba(idx, info, 0);
	a_to_b(info, tmp[1]);
	b_to_a(info, tmp[2]);
}
