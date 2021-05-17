/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:47:27 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:47:28 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	v_unit(t_vec vector1)
{
	t_vec	vector;

	vector.x = vector1.x / vec_length(vector1);
	vector.y = vector1.y / vec_length(vector1);
	vector.z = vector1.z / vec_length(vector1);
	return (vector);
}

t_vec	vec_min(t_vec vec1, t_vec vec2)
{
	t_vec	vector;

	vector.x = fmin(vec1.x, vec2.x);
	vector.y = fmin(vec1.y, vec2.y);
	vector.z = fmin(vec1.z, vec2.z);
	return (vector);
}

t_vec	vsymmetric(t_point p1, t_point stan)
{
	t_point	result;

	result.x = 2 * stan.x - p1.x;
	result.y = 2 * stan.y - p1.y;
	result.z = 2 * stan.z - p1.z;
	return (result);
}
