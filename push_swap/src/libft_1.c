/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:11:51 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:11:51 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoi(char *str)
{
	int	minus;
	long long	answer;
	int	i;

	i = 0;
	minus = 1;
	answer = 0;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			answer = answer * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (minus * answer);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

int		check_sorted_a(t_info *info, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;

	i = -1;
	if (info->stack[A]->size != r)
		return (0);
	now = info->stack[A]->head->next;
	while (++i < r && now->flag)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	i = -1;
	now = info->stack[A]->head->next;
	while (++i < r && now->flag)
	{
		if (tmp_arr[i] != now->data)
			return (0);
		now = now->next;
	}
	return (1);
}