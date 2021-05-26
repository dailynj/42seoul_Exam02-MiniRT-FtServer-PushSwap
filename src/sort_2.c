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
		if (info->stack[A]->head->next->data >
			info->stack[A]->head->next->next->data)
			sab(info, A);
	if (r == 3)
	{
		a = info->stack[A]->head->next->data;
		b = info->stack[A]->head->next->next->data;
		c = info->stack[A]->head->next->next->next->data;
		if (b < a)
			sort_aa(a, b, c, info);
		else if (a < c && c < b)
		{
			rab(info, A);
			sab(info, A);
			rrab(info, A);
		}
		else if (c < a && a < b)
		{
			sab(info, A);
			rab(info, A);
			sab(info, A);
			rrab(info, A);
		}
	}
}

void	sort_aa(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
		sab(info, A);
	else if (b < c && c < a)
	{
		rab(info, A);
		sab(info, A);
		rrab(info, A);
		sab(info, A);
	}
	else if (c < b && b < a)
	{
		sab(info, A);
		rab(info, A);
		sab(info, A);
		rrab(info, A);
		sab(info, A);
	}
}

void	sort_b(t_info *info, int r)
{
	int a;
	int b;
	int c;

	if (r == 2)
		if (info->stack[A]->head->next->data <
			info->stack[A]->head->next->next->data)
		{
			sab(info, A);
			pab(info, A);
			pab(info, A);
		}
	if (r == 3)
	{
		a = info->stack[B]->head->next->data;
		b = info->stack[B]->head->next->next->data;
		c = info->stack[B]->head->next->next->next->data;
		if (b < a)
			sort_bb(a, b, c, info);
		else if (b > a && a > c)
		{
			rab(info, B);
			sab(info, B);
			rrab(info, B);
			sab(info, B);
		}
		else if (b > c && c > a)
			sab(info, B);
		pab(info, B);
		pab(info, B);
		pab(info, B);
	}
}

void	sort_bb(int a, int b, int c, t_info *info)
{
	if (a > b && b > c)
	{
		sab(info, B);
		rab(info, B);
		sab(info, B);
		rrab(info, B);
		sab(info, B);
	}
	else if (a > c && c > b)
	{
		sab(info, B);
		rab(info, B);
		sab(info, B);
		rrab(info, B);
	}
	else if (c > a && a > b)
	{
		rab(info, B);
		sab(info, B);
		rrab(info, B);
	}
}
