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

void	sort_3elements_b(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->stack[B]->head->next->data;
	b = info->stack[B]->head->next->next->data;
	c = info->stack[B]->head->next->next->next->data;
	if (b < a && a < c)
	{
		push_tail_rb(info);
		push_tail_sb(info);
		push_tail_rrb(info);
		push_tail_sb(info);
	}
	else if (c < a && a < b)
		push_tail_sb(info);
	else
	{
		sort_bb(a, b, c, info);
	}
	push_tail_pa(info);
	push_tail_pa(info);
	push_tail_pa(info);
}

void	sort_b(t_info *info, int r)
{
	if (r == 1)
		push_tail_pa(info);
	else if (r == 2)
	{
		if (info->stack[B]->head->next->data <
				info->stack[B]->head->next->next->data)
			push_tail_sb(info);
		push_tail_pa(info);
		push_tail_pa(info);
	}
	else if (r == 3 && info->stack[B]->size == 3)
		sort_3b(info);
	else if (r == 3)
		sort_3elements_b(info);
}

void	sort_bb(int a, int b, int c, t_info *info)
{
	if (a < b && b < c)
	{
		push_tail_sb(info);
		push_tail_rb(info);
		push_tail_sb(info);
		push_tail_rrb(info);
		push_tail_sb(info);
	}
	else if (a < c && c < b)
	{
		push_tail_sb(info);
		push_tail_rb(info);
		push_tail_sb(info);
		push_tail_rrb(info);
	}
	else if (b < c && c < a)
	{
		push_tail_rb(info);
		push_tail_sb(info);
		push_tail_rrb(info);
	}
}
