/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:39:01 by najlee            #+#    #+#             */
/*   Updated: 2021/05/26 21:41:28 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quicksort(int arr[], int left, int right)
{
	int	l_;
	int	r_;
	int	temp;
	int pivot;

	pivot = arr[(left + right) / 2];
	l_ = left;
	r_ = right;
	while (l_ <= r_)
	{
		while (arr[l_] < pivot)
			l_++;
		while (arr[r_] > pivot)
			r_--;
		if (l_ <= r_)
		{
			if (l_ != r_)
			{
				temp = arr[l_];
				arr[l_] = arr[r_];
				arr[r_] = temp;
			}
			l_++;
			r_--;
		}
	}
	if (left < r_)
		quicksort(arr, left, r_);
	if (l_ < right)
		quicksort(arr, l_, right);
}
