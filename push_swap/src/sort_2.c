/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:32:39 by najlee            #+#    #+#             */
/*   Updated: 2021/05/26 21:32:40 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a(t_info *info, int r)
{
	int a;
	int b;
	int c;

	if (r == 2)
	{
		if (info->stack[A]->head->next->data > info->stack[A]->head->next->next->data)
		{
			push_tail(SA, &info->cmd);
			sab(info, A, 1);
		}
	}
	else if (r == 3 && info->stack[A]->size == 3)
		sort_3a(info);
	else if (r == 3)
	{
		a = info->stack[A]->head->next->data;
		b = info->stack[A]->head->next->next->data;
		c = info->stack[A]->head->next->next->next->data;
		if (a < c && c < b)
		{	
			push_tail(RA, &info->cmd);
			rab(info, A, 1);
			push_tail(SA, &info->cmd);
			sab(info, A, 1);
			push_tail(RRA, &info->cmd);
			rrab(info, A, 1);
		}
		else if (b < c && c < a)
		{
			push_tail(SA, &info->cmd);
			sab(info, A, 1);
			push_tail(RA, &info->cmd);
			rab(info, A, 1);
			push_tail(SA, &info->cmd);
			sab(info, A, 1);
			push_tail(RRA, &info->cmd);
			rrab(info, A, 1);
		}
		else
			sort_aa(a, b, c, info);
	}
}

void	sort_aa(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
	{
		push_tail(SA, &info->cmd);
		sab(info, A, 1);
	}
	else if (c < a && a < b)
	{
		push_tail(RA, &info->cmd);
		rab(info, A, 1);
		push_tail(SA, &info->cmd);
		sab(info, A, 1);
		push_tail(RRA, &info->cmd);
		rrab(info, A, 1);
		push_tail(SA, &info->cmd);
		sab(info, A, 1);
	}
	else if (c < b && b < a)
	{
		push_tail(SA, &info->cmd);
		sab(info, A, 1);
		push_tail(RA, &info->cmd);
		rab(info, A, 1);
		push_tail(SA, &info->cmd);
		sab(info, A, 1);
		push_tail(RRA, &info->cmd);
		rrab(info, A, 1);
		push_tail(SA, &info->cmd);
		sab(info, A, 1);
	}
}

void	sort_b(t_info *info, int r)
{
	int a;
	int b;
	int c;

	if (r == 1)
	{
		push_tail(PA, &info->cmd);
		pab(info, A);
	}
	else if (r == 2)
	{
		if (info->stack[B]->head->next->data < info->stack[B]->head->next->next->data)
		{
			push_tail(SB, &info->cmd);
			sab(info, B, 1);
		}
		push_tail(PA, &info->cmd);
		push_tail(PA, &info->cmd);
		pab(info, A);
		pab(info, A);
	}
	else if (r == 3 && info->stack[B]->size == 3)
		sort_3b(info);
	else if (r == 3)
	{
		a = info->stack[B]->head->next->data;
		b = info->stack[B]->head->next->next->data;
		c = info->stack[B]->head->next->next->next->data;
		if (b < a && a < c)
		{
			push_tail(RB, &info->cmd);
			rab(info, B, 1);
			push_tail(SB, &info->cmd);
			sab(info, B, 1);
			push_tail(RRB, &info->cmd);
			rrab(info, B, 1);
			push_tail(SB, &info->cmd);
			sab(info, B, 1);
		}
		else if (c < a && a < b)
		{
			push_tail(SB, &info->cmd);
			sab(info, B, 1);
		}
		else
		{
			sort_bb(a, b, c, info);
		}
		push_tail(PA, &info->cmd);
		push_tail(PA, &info->cmd);
		push_tail(PA, &info->cmd);
		pab(info, A);
		pab(info, A);
		pab(info, A);
	}
}

void	sort_bb(int a, int b, int c, t_info *info)
{
	if (a < b && b < c)
	{
		push_tail(SB, &info->cmd);
		sab(info, B, 1);
		push_tail(RB, &info->cmd);
		rab(info, B, 1);
		push_tail(SB, &info->cmd);
		sab(info, B, 1);
		push_tail(RRB, &info->cmd);
		rrab(info, B, 1);
		push_tail(SB, &info->cmd);
		sab(info, B, 1);
	}
	else if (a < c && c < b)
	{
		push_tail(SB, &info->cmd);
		sab(info, B, 1);
		push_tail(RB, &info->cmd);
		rab(info, B, 1);
		push_tail(SB, &info->cmd);
		sab(info, B, 1);
		push_tail(RRB, &info->cmd);
		rrab(info, B, 1);
	}
	else if (b < c && c < a)
	{
		push_tail(RB, &info->cmd);
		rab(info, B, 1);
		push_tail(SB, &info->cmd);
		sab(info, B, 1);
		push_tail(RRB, &info->cmd);
		rrab(info, B, 1);
	}
}
