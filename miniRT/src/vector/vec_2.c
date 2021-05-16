/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:47:22 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:47:54 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	vec_mul(t_vec vector1, t_vec vector2)
{
	t_vec	vector;

	vector.x = vector1.x * vector2.x;
	vector.y = vector1.y * vector2.y;
	vector.z = vector1.z * vector2.z;
	return (vector);
}

t_vec	vec_mul_num(double t, t_vec vector1)
{
	t_vec	vector;

	vector.x = vector1.x * t;
	vector.y = vector1.y * t;
	vector.z = vector1.z * t;
	return (vector);
}

t_vec	vec_div(double t, t_vec vector1)
{
	t_vec	vector;

	vector.x = vector1.x * (1 / t);
	vector.y = vector1.y * (1 / t);
	vector.z = vector1.z * (1 / t);
	return (vector);
}

double	vec_dot(t_vec vector1, t_vec vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y +
						vector1.z * vector2.z);
}

t_vec	vec_cross(t_vec vec, t_vec vec2)
{
	t_vec	vector;

	vector.x = vec.y * vec2.z - vec.z * vec2.y;
	vector.y = vec.z * vec2.x - vec.x * vec2.z;
	vector.z = vec.x * vec2.y - vec.y * vec2.x;
	return (vector);
}
