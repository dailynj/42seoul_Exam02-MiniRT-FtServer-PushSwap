/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:41:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:46:15 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vec	to_vec(char **data)
{
	t_vec	result;

	result.x = ft_atod(data[0]);
	result.y = ft_atod(data[1]);
	result.z = ft_atod(data[2]);
	return (result);
}

t_color	to_color(char **data)
{
	t_vec	result;

	result.x = ft_atod(data[0]) / 255.0;
	result.y = ft_atod(data[1]) / 255.0;
	result.z = ft_atod(data[2]) / 255.0;
	return (result);
}
