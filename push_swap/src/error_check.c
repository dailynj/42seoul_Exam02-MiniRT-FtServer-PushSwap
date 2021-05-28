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

int		argv_check(long long arr[], int num)
{
	int idx;

	idx = -1;
	if (arr[num] > 2147483647 || arr[num] < -2147483647)
		return (0);
	while (++idx < num)
	{
		if (arr[idx] == arr[num])
			return (0);
	}
	return (1);
}

int		print_error(char *str)
{
	printf("%s", str);
	return (0);
}
