/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:55 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:47:18 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

double	vec_length(t_vec vector)
{
	return (sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
}

double	vec_length_2(t_vec vector)
{
	return (pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

t_vec	vec_add(t_vec vector1, t_vec vector2)
{
	t_vec	vector;

	vector.x = vector1.x + vector2.x;
	vector.y = vector1.y + vector2.y;
	vector.z = vector1.z + vector2.z;
	return (vector);
}

t_vec	v_minus(t_vec vector1, t_vec vector2)
{
	t_vec	vector;

	vector.x = vector1.x - vector2.x;
	vector.y = vector1.y - vector2.y;
	vector.z = vector1.z - vector2.z;
	return (vector);
}
