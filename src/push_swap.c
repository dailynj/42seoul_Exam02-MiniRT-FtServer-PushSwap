/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:12:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/29 02:59:24 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cmd_zip(t_list *now)
{
	now = now->next;
	while (now->flag == 1 && now->next->flag == 1)
	{
		if ((now->data == SA && now->next->data == SB) ||
			(now->data == SB && now->next->data == SA))
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = SS;
			free(now);
		}
		else if ((now->data == RA && now->next->data == RB) ||
			(now->data == RB && now->next->data == RA))
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = RR;
			free(now);
		}
		else if ((now->data == RRA && now->next->data == RRB) ||
			(now->data == RRB && now->next->data == RRA))
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = RRR;
			free(now);
		}
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

void	print_cmd(t_stack *stack)
{
	t_list *now;

	now = stack->head->next;
	cmd_zip(stack->head);
	while (now->flag == 1)
	{
		print_cmd_2(now->data);
		now = now->next;
	}
}

int		push_swap(int argc, char **argv)
{
	int		idx;
	t_info	*info;
	t_box	*box;

	idx = -1;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	if (!(box = (t_box *)malloc(sizeof(t_box))))
	{
		free(info);
		return (0);
	}
	if (init_list(info) == 0)
		return (0);
	if (!(box->arr = malloc(argc * sizeof(long long))))
	{
		free_info(info);
		free_box(box);
		return (0);
	}
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
		{
			free_info(info);
			free_box(box);
			return (print_error());
		}
	}
	push_all(info->stack[A], box->arr, argc - 1);
	if (check_sorted_a(info, argc - 1))
	{
		free_info(info);
		free_box(box);
		return (0);
	}
	a_to_b(info, argc - 1);
	print_cmd(&info->cmd);

	free_two_list(info);
	free_info(info);
	free_cmd(info);
	free(info);
	free_box(box);
	return (0);
}

int		main(int argc, char **argv)
{
	push_swap(argc, argv);
	while(1)
		;
	return (0);
}