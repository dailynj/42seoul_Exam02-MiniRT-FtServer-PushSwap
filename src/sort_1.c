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

void	a_to_b(t_info *info, int r)
{
	t_idx	*idx;
	int		i;
	int		*pivot;
	int		tmp[5];

	if (!(idx = malloc(sizeof(t_idx))))
		return ;
	init_idx(idx);
	i = -1;
	if (r <= 3)
		return (sort_a(info, r));
	if (!info->stack[A]->head->next->flag)
		return ;
	pivot = find_pivot(info, A, r);
	classification_a(info, r, pivot, idx);
	tmp[0] = idx->ra;
	tmp[1] = idx->rb;
	tmp[2] = idx->pb;
	optimization_a(idx, info);
	free(pivot);
	free(idx);
	a_to_b(info, tmp[0]);
	b_to_a(info, tmp[1]);
	b_to_a(info, tmp[2] - tmp[1]);
}

void	b_to_a(t_info *info, int r)
{
	t_idx	*idx;
	int		i;
	int		*pivot;
	int		tmp[3];

	if (!(idx = malloc(sizeof(t_idx))))
		return ;
	init_idx(idx);
	i = -1;
	if (r <= 3)
		return (sort_b(info, r));
	if (!info->stack[B]->head->next->flag)
		return ;
	pivot = find_pivot(info, B, r);
	classification_b(info, r, pivot, idx);
	free(pivot);
	tmp[0] = idx->ra;
	tmp[1] = idx->rb;
	tmp[2] = idx->pa;
	a_to_b(info, tmp[2] - tmp[0]);
	optimization_b(idx, info);
	a_to_b(info, tmp[0]);
	b_to_a(info, tmp[1]);
}
