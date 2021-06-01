/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tail_srp_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:58:18 by najlee            #+#    #+#             */
/*   Updated: 2021/05/31 15:58:21 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_tail_ra(t_info *info)
{
	push_tail(RA, &info->cmd);
	rab(info, A);
}

void	push_tail_rb(t_info *info)
{
	push_tail(RB, &info->cmd);
	rab(info, B);
}

void	push_tail_sa(t_info *info)
{
	push_tail(SA, &info->cmd);
	sab(info, A);
}

void	push_tail_sb(t_info *info)
{
	push_tail(SB, &info->cmd);
	sab(info, B);
}
