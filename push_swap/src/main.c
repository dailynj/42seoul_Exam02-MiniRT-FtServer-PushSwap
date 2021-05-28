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

void	print_stack(t_stack *stack, int num) //확인용
{
	t_list *now;

	now = stack->head->next;
	if (num == A)
		printf("\n<AAAAAA>\n");
	else
		printf("\n<BBBBBB>\n");
	while (now->flag == 1)
	{
		printf("%d -> ", now->data);
		now = now->next;
	}
	printf("\n");
}

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

void	print_cmd(t_info *info, t_stack *stack) //확인용
{
	t_list *now;
	(void) info;
	
	now = stack->head->next;
	cmd_zip(stack);
	// printf("\n<cmd>\n");
	while(now->flag == 1)
	{
		if (now->data == SA)
		{
			printf("sa\n");
			// sab(info, A, 1);
		}
		else if (now->data == SB)
		{
			printf("sb\n");
			// sab(info, B, 1);
		}
		else if (now->data == SS)
		{
			printf("ss\n");
			// ss(info);
		}
		else if (now->data == PA)
		{
			printf("pa\n");
			// pab(info, A);
		}
		else if (now->data == PB)
		{
			printf("pb\n");
			// pab(info, B);
		}
		else if (now->data == RA)
		{
			printf("ra\n");
			// rab(info, A, 1);
		}
		else if (now->data == RB)
		{
			printf("rb\n");
			// rab(info, B, 1);
		}
		else if (now->data == RR)
		{
			printf("rr\n");
			// rr(info);
		}
		else if (now->data == RRA)
		{
			printf("rra\n");
			// rrab(info, A, 1);
		}
		else if (now->data == RRB)
		{
			printf("rrb\n");
			// rrab(info, B, 1);
		}
		else if (now->data == RRR)
		{
			printf("rrr\n");
			// rrr(info);
		}
		now = now->next;
	}
	// printf("\n");
}

int		main(int argc, char **argv)
{
	int		idx;
	t_info	*info;
	t_box	*box;

	idx = -1;
	info = (t_info *)malloc(sizeof(t_info));
	box = (t_box *)malloc(sizeof(t_box));
	init_list(info);  //list 초기화
	if (!(box->arr = malloc(argc * sizeof(long long))))
		return (0);
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
			// 문자가 들어왔을 때 + 인자 에러 체크(정수 범위, 중복)
			return (print_error("Error\n"));
	}
	// init_arr(box, argc - 1);
	push_all(info->stack[A], box->arr, argc - 1);  // A 에 인자로 들어온 값 넣어주기
	// if (argc == 4)
	// 	sort_3(info);
	// else

	// print_stack(info->stack[A], A);
	// print_stack(info->stack[B], B);
	// 정렬됬으면 바로 빠져나오기
	if (check_sorted_a(info, argc - 1))
		return (0);
	a_to_b(info, argc - 1);

	// ------- 출력 확인
	// sab(info, A, 1);
	// pab(info, B);
	// pab(info, B);
	// pab(info, B);
	// sab(info, A, 1);
	// pab(info, A);
	// pab(info, A);
	// pab(info, A);
	print_cmd(info, &info->cmd); // 안씀
	// print_stack(info->stack[A], A);
	// print_stack(info->stack[B], B);
	// -------

	return (0);
}