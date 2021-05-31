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

int		push_swap(int argc, char **argv)
{
	t_info	*info;
	t_box	*box;

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
		return (free_info_box(info, box));
	if (get_argv(argc, box, info, argv) == 0)
		return (0);
	push_all(info->stack[A], box->arr, argc - 1);
	if (check_sorted_a(info, argc - 1))
		return (free_info_box(info, box));
	a_to_b(info, argc - 1);
	print_cmd(&info->cmd);
	final_free(info, box);
	return (0);
}

int		main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
