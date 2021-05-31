/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:58:05 by najlee            #+#    #+#             */
/*   Updated: 2021/05/31 15:58:06 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2_element_a(t_info *info)
{
	if (info->stack[A]->head->next->data >
				info->stack[A]->head->next->next->data)
		push_tail_sa(info);
}

void	sort_3_element_a(t_info *info)
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
	{
		push_tail_sa(info);
		push_tail_ra(info);
		push_tail_sa(info);
		push_tail_rra(info);
	}
	else
		sort_short_aa(a, b, c, info);
}

void	sort_2_element_b(t_info *info)
{
	if (info->stack[B]->head->next->data <
		info->stack[B]->head->next->next->data)
		push_tail_sb(info);
	push_tail_pa(info);
	push_tail_pa(info);
}

void	sort_3_element_b(t_info *info)
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
	{
		push_tail_sb(info);
	}
	else
		sort_short_bb(a, b, c, info);
	push_tail_pa(info);
	push_tail_pa(info);
	push_tail_pa(info);
}
