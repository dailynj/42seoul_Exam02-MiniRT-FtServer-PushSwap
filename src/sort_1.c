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
	int ra_;
	int pb_;
	int rb_;
	int i;
	int *pivot;

	ra_ = 0;
	pb_ = 0;
	rb_ = 0;
	i = -1;
	pivot = find_pivot(info, A, r);
	if (r <= 3)
		return (sort_a(info, r));
	while (r--)
	{
		if (info->stack[A]->head->next->data >= pivot[1])
		{
			rab(info, A, 1);
			ra_++;
		}
		else
		{
			pab(info, B);
			pb_++;
			if (info->stack[B]->head->next->data >= pivot[0])
			{
				rab(info, B, 1);
				rb_++;
			}
		}
	}
	// rrr 로 합칠 수 있음
	while (++i < ra_)
		rrab(info, A, 1);
	i = -1;
	while (++i < rb_)
		rrab(info, B, 1);
	a_to_b(info, ra_);
	b_to_a(info, rb_);
	b_to_a(info, pb_ - rb_);
}

void	b_to_a(t_info *info, int r)
{
	int rb_;
	int pa_;
	int ra_;
	int	i;
	int	*pivot;

	rb_ = 0;
	pa_ = 0;
	ra_ = 0;
	i = -1;
	if (r <= 3)
		return (sort_b(info, r));
	pivot = find_pivot(info, B, r);
	while (r--)
	{
		if (info->stack[B]->head->next->data < pivot[0])
		{
			rab(info, B, 1);
			rb_++;
		}
		else
		{
			pab(info, A);
			pa_++;
			if (info->stack[B]->head->next->data >= pivot[1])
			{
				rab(info, A, 1);
				ra_++;
			}
		}
	}
	a_to_b(info, pa_ - ra_);
	// rrr 로 합칠 수 있음
	while (++i < ra_)
		rrab(info, A, 1);
	i = -1;
	while (++i < rb_)
		rrab(info, B, 1);
	a_to_b(info, rb_);
	b_to_a(info, ra_);
}
