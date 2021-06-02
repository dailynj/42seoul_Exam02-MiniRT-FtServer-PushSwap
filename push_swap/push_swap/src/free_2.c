/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:01:46 by najlee            #+#    #+#             */
/*   Updated: 2021/05/28 18:01:47 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		free_info_box(t_info *info, t_box *box)
{
	free_info(info);
	free_box(box);
	return (0);
}

void	final_free(t_info *info, t_box *box)
{
	free_two_list(info);
	free_info(info);
	free_cmd(info);
	free(info);
	free_box(box);
}

void	free_3_list(t_list *list1, t_list *list2, t_list *list3)
{
	free(list1);
	free(list2);
	free(list3);
}

void	free_2_list(t_list *list1, t_list *list2)
{
	free(list1);
	free(list2);
}

void	free_2_stack(t_stack *stack1, t_stack *stack2)
{
	free(stack1);
	free(stack2);
}
