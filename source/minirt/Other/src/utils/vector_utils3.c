/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:56:41 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:00:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec	v_normalize(t_vec vec)
{
	t_vec	result;
	double	len;

	len = v_len(vec);
	result.x = vec.x / len;
	result.y = vec.y / len;
	result.z = vec.z / len;
	return (result);
}

t_vec	v_cross(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}

t_vec	v_min(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	result.x = fmin(vec1.x, vec2.x);
	result.y = fmin(vec1.y, vec2.y);
	result.z = fmin(vec1.z, vec2.z);
	return (result);
}
