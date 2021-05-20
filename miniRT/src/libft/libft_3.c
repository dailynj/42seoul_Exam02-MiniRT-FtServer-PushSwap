/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 13:58:15 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	free_print_error(char **ol, char *str)
{
	ft_freeall(ol);
	return (print_error(str));
}

int	free2_print_error(char **ol, char **ol2, char *str)
{
	ft_freeall(ol);
	ft_freeall(ol2);
	return (print_error(str));
}

int	free3_print_error(char **ol, char **ol2, char **ol3, char *str)
{
	ft_freeall(ol);
	ft_freeall(ol2);
	ft_freeall(ol3);
	return (print_error(str));
}
