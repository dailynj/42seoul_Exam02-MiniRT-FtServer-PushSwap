/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:39:19 by najlee            #+#    #+#             */
/*   Updated: 2021/06/01 15:39:20 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3a(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->stack[A]->head->next->data;
	b = info->stack[A]->head->next->next->data;
	c = info->stack[A]->head->next->next->next->data;
	if (a < c && c < b)
	{
		push_tail_ra(info);
		push_tail_sa(info);
		push_tail_rra(info);
	}
	else if (b < c && c < a)
		push_tail_ra(info);
	else
		sort_33a(a, b, c, info);
}

void	sort_33a(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
		push_tail_sa(info);
	else if (c < a && a < b)
		push_tail_rra(info);
	else if (c < b && b < a)
	{
		push_tail_sa(info);
		push_tail_rra(info);
	}
}

void	sort_3b(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->stack[B]->head->next->data;
	b = info->stack[B]->head->next->next->data;
	c = info->stack[B]->head->next->next->next->data;
	if (b < a && a < c)
		push_tail_rrb(info);
	else if (c < a && a < b)
		push_tail_sb(info);
	else
		sort_33b(a, b, c, info);
	push_tail_pa(info);
	push_tail_pa(info);
	push_tail_pa(info);
}

void	sort_33b(int a, int b, int c, t_info *info)
{
	if (a < b && b < c)
	{
		push_tail_sb(info);
		push_tail_rrb(info);
	}
	else if (a < c && c < b)
		push_tail_rb(info);
	else if (b < c && c < a)
	{
		push_tail_rb(info);
		push_tail_sb(info);
		push_tail_rrb(info);
	}
}
