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

void	cmd_zip(t_stack *stack)
{
	t_list *now;

	now = stack->head->next;
	while (now->flag == 1 && now->next->flag == 1)
	{
		if ((now->data == SA && now->next->data == SB) ||
			(now->data == SB && now->next->data == SA))
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = SS;
		}
		else if ((now->data == RA && now->next->data == RB) ||
			(now->data == RB && now->next->data == RA))
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = RR;
		}
		else if ((now->data == RRA && now->next->data == RRB) ||
			(now->data == RRB && now->next->data == RRA))
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = RRR;
		}
		now = now->next;
	}
}

void	print_cmd_2(int cmd)
{
	if (cmd == SA)
		printf("sa\n");
	else if (cmd == SB)
		printf("sb\n");
	else if (cmd == SS)
		printf("ss\n");
	else if (cmd == PA)
		printf("pa\n");
	else if (cmd == PB)
		printf("pb\n");
	else if (cmd == RA)
		printf("ra\n");
	else if (cmd == RB)
		printf("rb\n");
	else if (cmd == RR)
		printf("rr\n");
	else if (cmd == RRA)
		printf("rra\n");
	else if (cmd == RRB)
		printf("rrb\n");
	else if (cmd == RRR)
		printf("rrr\n");
}

void	print_cmd(t_stack *stack)
{
	t_list *now;

	now = stack->head->next;
	cmd_zip(stack);
	while (now->flag == 1)
	{
		print_cmd_2(now->data);
		now = now->next;
	}
}

int		main(int argc, char **argv)
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
		free(info);
		free_box(box);
		return (0);
	}
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
			return (print_error("Error\n"));
	}
	push_all(info->stack[A], box->arr, argc - 1);
	if (check_sorted_a(info, argc - 1))
		return (0);
	a_to_b(info, argc - 1);
	free_info(info); // 모두 free 해야됨
	free_box(box);
	print_cmd(&info->cmd);
	// while(1)
	// 	;
	return (0);
}
