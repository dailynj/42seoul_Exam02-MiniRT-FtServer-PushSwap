/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:12:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:12:10 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cmd_zip(t_stack *stack)
{
	t_list *now;
	
	now = stack->head->next;
	while(now->flag == 1 && now->next->flag == 1)
	{
		if (now->data == SA && now->next->data == SB)
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = SS;
		}
		else if (now->data == RA && now->next->data == RB)
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = RR;
		}
		else if (now->data == RRA && now->next->data == RRB)
		{
			now->prev->next = now->next;
			now->next->prev = now->prev;
			now->next->data = RRR;
		}
		now = now->next;
	}
}

void	print_cmd(t_info *info, t_stack *stack)
{
	t_list *now;
	(void) info;
	
	now = stack->head->next;
	cmd_zip(stack);
	while(now->flag == 1)
	{
		if (now->data == SA)
			printf("sa\n");
		else if (now->data == SB)
			printf("sb\n");
		else if (now->data == SS)
			printf("ss\n");
		else if (now->data == PA)
			printf("pa\n");
		else if (now->data == PB)
			printf("pb\n");
		else if (now->data == RA)
			printf("ra\n");
		else if (now->data == RB)
			printf("rb\n");
		else if (now->data == RR)
			printf("rr\n");
		else if (now->data == RRA)
			printf("rra\n");
		else if (now->data == RRB)
			printf("rrb\n");
		else if (now->data == RRR)
			printf("rrr\n");
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
		final_free();
	if (init_list(info) == 0)
		final_free();
	if (!(box->arr = malloc(argc * sizeof(long long))))
		final_free();
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
			return (print_error("Error\n"));
	}
	push_all(info->stack[A], box->arr, argc - 1);
	if (check_sorted_a(info, argc - 1))
		final_free();
	a_to_b(info, argc - 1);

	free(info); // 모두 free 해야됨 
	free(box);

	print_cmd(info, &info->cmd);
	return (0);
}