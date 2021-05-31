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

void	sort_short_a(t_info *info, int r)
{
	if (r == 2)
		sort_2_element_a(info);
	else if (r == 3 && info->stack[A]->size == 3)
		sort_3a(info);
	else if (r == 3)
		sort_3_element_a(info);
}

void	sort_short_aa(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
	{
		push_tail_sa(info);
	}
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

void	sort_short_b(t_info *info, int r)
{
	if (r == 1)
		push_tail_pa(info);
	else if (r == 2)
		sort_2_element_b(info);
	else if (r == 3 && info->stack[B]->size == 3)
		sort_3b(info);
	else if (r == 3)
		sort_3_element_b(info);
}

void	sort_short_bb(int a, int b, int c, t_info *info)
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
