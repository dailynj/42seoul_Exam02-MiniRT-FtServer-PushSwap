/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:12:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/31 23:23:34 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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

int		main(int argc, char **argv)
{
	int		idx;
	t_info	*info;
	t_box	*box;

	idx = -1;
	if (argc == 1)
		return (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	if (!(box = (t_box *)malloc(sizeof(t_box))))
	{
		free(info);
		return (0);
	}
	if (init_list(info) == 0)
		return (free_info_box(info, box));
	if (!(box->arr = malloc(argc * sizeof(long long))))
		return (free_info_box(info, box));
	fill_arr(argc, argv, box, info);
	push_all(info->stack[A], box->arr, argc - 1);
	if (check_sorted_a(info, argc - 1))
		return (free_info_box(info, box));
	a_to_b(info, argc - 1);
	print_cmd(&info->cmd);
	final_free(info, box);
	// while(1)
	// 	;
	return (0);
}