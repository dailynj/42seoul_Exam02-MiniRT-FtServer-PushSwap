/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:03:00 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:03:57 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec	v_multiply_2(t_vec vec1, t_vec vec2)
{
	t_vec	vec3;

	vec3.x = vec1.x * vec2.x;
	vec3.y = vec1.y * vec2.y;
	vec3.z = vec1.z * vec2.z;
	return (vec3);
}

double	v_dot(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

double	v_len_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	v_len(t_vec vec)
{
	return (sqrt(v_len_squared(vec)));
}
