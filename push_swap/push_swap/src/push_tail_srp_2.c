/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tail_srp_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:58:28 by najlee            #+#    #+#             */
/*   Updated: 2021/05/31 15:58:29 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_tail_pa(t_info *info)
{
	push_tail(PA, &info->cmd);
	pab(info, A);
}

void	push_tail_pb(t_info *info)
{
	push_tail(PB, &info->cmd);
	pab(info, B);
}

void	push_tail_rra(t_info *info)
{
	push_tail(RRA, &info->cmd);
	rrab(info, A);
}

void	push_tail_rrb(t_info *info)
{
	push_tail(RRB, &info->cmd);
	rrab(info, B);
}
