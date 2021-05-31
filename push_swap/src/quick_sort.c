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

void	swap(int arr[], int a, int b)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int		partition(int arr[], int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= arr[low])
			low++;
		while (high >= (left + 1) && pivot <= arr[high])
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return (high);
}

void	quicksort(int arr[], int left, int right)
{
	int pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}
