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

void	sort_3elements_a(t_info *info)
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
		sort_aa(a, b, c, info);
}

void	sort_a(t_info *info, int r)
{
	if (r == 2)
	{
		if (info->stack[A]->head->next->data >
					info->stack[A]->head->next->next->data)
			push_tail_sa(info);
	}
	else if (r == 3 && info->stack[A]->size == 3)
		sort_3a(info);
	else if (r == 3)
		sort_3elements_a(info);
}

void	sort_aa(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
		push_tail_sa(info);
	else if (c < a && a < b)
	{
		push_tail_ra(info);
		push_tail_sa(info);
		push_tail_rra(info);
		push_tail_sa(info);
	}
	else if (c < b && b < a)
	{
		push_tail_sa(info);
		push_tail_ra(info);
		push_tail_sa(info);
		push_tail_rra(info);
		push_tail_sa(info);
	}
}
