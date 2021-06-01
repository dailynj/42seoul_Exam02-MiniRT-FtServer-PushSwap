/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:15:47 by najlee            #+#    #+#             */
/*   Updated: 2021/06/01 15:15:48 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		fill_arr(int argc, char **argv, t_box *box, t_info *info)
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

void	init_idx(t_idx *idx)
{
	idx->ra = 0;
	idx->rb = 0;
	idx->pa = 0;
	idx->pb = 0;
	idx->sa = 0;
	idx->sb = 0;
	idx->tmp = 0;
}
