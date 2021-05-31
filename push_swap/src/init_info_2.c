/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:11:57 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:11:58 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*node(int value, t_list *prev, t_list *next)
{
	t_list	*new_list;

	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new_list->prev = prev;
	new_list->next = next;
	new_list->data = value;
	new_list->flag = 1;
	return (new_list);
}

int		*find_pivot(t_info *info, int num, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;
	int		*pivot;

	i = -1;
	pivot = malloc(2 * sizeof(int));
	now = info->stack[num]->head->next;
	while (++i < r && now->flag)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	pivot[1] = tmp_arr[2 * r / 3];
	pivot[0] = tmp_arr[r / 3];
	return (pivot);
}

int		get_argv(int argc, t_box *box, t_info *info, char **argv)
{
	int idx;

	idx = -1;
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
		{
			free_info_box(info, box);
			return (print_error());
		}
	}
	return (1);
}
