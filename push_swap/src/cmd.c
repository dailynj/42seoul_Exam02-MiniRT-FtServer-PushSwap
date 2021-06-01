/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:23:23 by najlee            #+#    #+#             */
/*   Updated: 2021/06/01 15:23:24 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_cmd(t_info *info)
{
	info->cmd.head->next = info->cmd.tail;
	info->cmd.head->prev = NULL;
	info->cmd.tail->prev = info->cmd.head;
	info->cmd.tail->next = NULL;
	info->cmd.head->flag = 0;
	info->cmd.tail->flag = 0;
}

int		init_cmd(t_info *info)
{
	if (!(info->cmd.head = (t_list *)malloc(sizeof(t_list))))
	{
		free_stack(info->stack[A]);
		free_stack(info->stack[B]);
		free(info);
		return (0);
	}
	if (!(info->cmd.tail = (t_list *)malloc(sizeof(t_list))))
	{
		free_stack(info->stack[A]);
		free_stack(info->stack[B]);
		free(info->cmd.head);
		free(info);
		return (0);
	}
	fill_cmd(info);
	return (1);
}

void	cmd_zip_2(t_list *now, int cmd)
{
	now->prev->next = now->next;
	now->next->prev = now->prev;
	now->next->data = cmd;
	free(now);
}

void	cmd_zip(t_list *now)
{
	now = now->next;
	while (now->flag == 1 && now->next->flag == 1)
	{
		if ((now->data == SA && now->next->data == SB) ||
			(now->data == SB && now->next->data == SA))
			cmd_zip_2(now, SS);
		else if ((now->data == RA && now->next->data == RB) ||
			(now->data == RB && now->next->data == RA))
			cmd_zip_2(now, RR);
		else if ((now->data == RRA && now->next->data == RRB) ||
			(now->data == RRB && now->next->data == RRA))
			cmd_zip_2(now, RRR);
		now = now->next;
	}
}

void	print_cmd_2(int cmd)
{
	if (cmd == SA)
		write(1, "sa\n", 3);
	else if (cmd == SB)
		write(1, "sb\n", 3);
	else if (cmd == SS)
		write(1, "ss\n", 3);
	else if (cmd == PA)
		write(1, "pa\n", 3);
	else if (cmd == PB)
		write(1, "pb\n", 3);
	else if (cmd == RA)
		write(1, "ra\n", 3);
	else if (cmd == RB)
		write(1, "rb\n", 3);
	else if (cmd == RR)
		write(1, "rr\n", 3);
	else if (cmd == RRA)
		write(1, "rra\n", 4);
	else if (cmd == RRB)
		write(1, "rrb\n", 4);
	else if (cmd == RRR)
		write(1, "rrr\n", 4);
}
