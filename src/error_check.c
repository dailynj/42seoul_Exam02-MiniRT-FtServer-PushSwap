/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:11:45 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:11:46 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 중복, int의 최대 최소 체크
int	argv_check(int arr[], int num, int argc)
{
	int idx;

	idx = -1;
	if (num > 2147483647 || num < -2147483647)
		return (0);
	while (++idx < argc)
	{
		if (arr[idx] == num)
			return (0);
	}
	return (1);
}
