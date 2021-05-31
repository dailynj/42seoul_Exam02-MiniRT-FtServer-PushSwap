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

	if (r <= 3)
		return (sort_a(info, r));
	if (!info->stack[A]->head->next->flag)
		return ;
	pivot = find_pivot(info, A, r);
	while (r--)
	{
		if (info->stack[A]->head->next->data >= pivot[1])
		{
			push_tail(RA, &info->cmd);
			rab(info, A);
			ra_++;
		}
		else
		{
			push_tail(PB, &info->cmd);
			pab(info, B);
			pb_++;
			if (info->stack[B]->head->next->data >= pivot[0] && info->stack[B]->size > 1)
			{
				push_tail(RB, &info->cmd);
				rab(info, B);
				rb_++;
			}
			else if (info->stack[B]->head->next->data >= pivot[0])
			{
				rb_++;
			}
		}
	}
	int tmp_ra = ra_;
	int tmp_rb = rb_;
	int tmp_pb = pb_;
	if (ra_ == info->stack[A]->size)
		ra_ = 0;
	if (rb_ == info->stack[B]->size)
		rb_ = 0;
	if ((info->stack[B]->size - rb_) < rb_)
	{
		if ((ra_ + info->stack[B]->size - rb_) < max(ra_, rb_))
		{
			rb_ = info->stack[B]->size - rb_;
			i = -1;
			while (++i < ra_)
			{
				push_tail(RRA, &info->cmd);
				rrab(info, A);
			}
			i = -1;
			while (++i < rb_)
			{
				push_tail(RB, &info->cmd);
				rab(info, B);
			}
		}
	}
	else{
		i = -1;
		while (++i < min(ra_, rb_))
		{
			push_tail(RRR, &info->cmd);
			rrr(info);
		}
		i = -1;
		if (ra_ > rb_)
		{
			while (++i < (ra_ - rb_))
			{
				push_tail(RRA, &info->cmd);
				rrab(info, A);
			}
		}
		else
		{
			while (++i < (rb_ - ra_))
			{
				push_tail(RRB, &info->cmd);
				rrab(info, B);
			}
		}
	}
	free(pivot);
	a_to_b(info, tmp_ra);
	b_to_a(info, tmp_rb);
	b_to_a(info, tmp_pb - tmp_rb);
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
	if (!info->stack[B]->head->next->flag)
		return ;
	pivot = find_pivot(info, B, r);
	while (r--)
	{
		int tmp = info->stack[B]->head->next->data;
		if (tmp < pivot[0])
		{	
			push_tail(RB, &info->cmd);
			rab(info, B);
			rb_++;
		}
		else
		{
			push_tail(PA, &info->cmd);
			pab(info, A);
			pa_++;
			if (tmp < pivot[1] && info->stack[A]->size > 1)
			{
				push_tail(RA, &info->cmd);
				rab(info, A);
				ra_++;
			}
			else if (tmp < pivot[1])
			{
				ra_++;
			}
		}
	}
	free(pivot);
	int tmp_ra = ra_;
	int tmp_rb = rb_;
	int tmp_pa = pa_;
	a_to_b(info, tmp_pa - tmp_ra);
	if (ra_ == info->stack[A]->size)
		ra_ = 0;
	if (rb_ == info->stack[B]->size)
		rb_ = 0;
	if ((info->stack[A]->size - ra_) < ra_)
	{
		if ((rb_ + info->stack[A]->size - ra_) < max(rb_, ra_))
		{
			ra_ = info->stack[A]->size - ra_;
			i = -1;
			while (++i < rb_)
			{
				push_tail(RRB, &info->cmd);
				rrab(info, B);
			}
			i = -1;
			while (++i < ra_)
			{
				push_tail(RA, &info->cmd);
				rab(info, A);
			}
		}
	}
	else{
		i = -1;
		while (++i < min(ra_, rb_))
		{
			push_tail(RRR, &info->cmd);
			rrr(info);
		}
		i = -1;
		if (rb_ > ra_)
		{
			while (++i < (rb_ - ra_))
			{
				push_tail(RRB, &info->cmd);
				rrab(info, B);
			}
		}
		else
		{
			while (++i < (ra_ - rb_))
			{
				push_tail(RRA, &info->cmd);
				rrab(info, A);
			}
		}
	}
	a_to_b(info, tmp_ra);
	b_to_a(info, tmp_rb);
}
