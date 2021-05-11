/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 09:18:14 by 42uym             #+#    #+#             */
/*   Updated: 2021/01/13 04:52:32 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_vec		reflect(t_vec v, t_vec n)
{
	return (v_minus(v, v_multiply(n, v_dot(v, n) * 2)));
}

void		set_face_normal(t_ray r, t_hit_record *rec)
{
	if (v_dot(r.dir, rec->normal) < 0)
		rec->front_face = TRUE;
	else
	{
		rec->normal = v_multiply(rec->normal, -1);
		rec->front_face = FALSE;
	}
}

int			is_inside(t_point p1, t_point p2, t_point p3, t_point p)
{
	t_vec	v1;
	t_vec	v2;

	v1 = v_cross(v_minus(p2, p1), v_minus(p, p1));
	v2 = v_cross(v_minus(p2, p1), v_minus(p3, p1));
	if (v_dot(v1, v2) < 0)
		return (0);
	v1 = v_cross(v_minus(p3, p1), v_minus(p, p1));
	v2 = v_cross(v_minus(p3, p1), v_minus(p2, p1));
	if (v_dot(v1, v2) < 0)
		return (0);
	v1 = v_cross(v_minus(p2, p3), v_minus(p, p3));
	v2 = v_cross(v_minus(p2, p3), v_minus(p1, p3));
	if (v_dot(v1, v2) < 0)
		return (0);
	return (1);
}

t_point		at(double t, t_ray ray)
{
	t_point at;

	at = v_plus(ray.origin, v_multiply(ray.dir, t));
	return (at);
}

t_ray		ray(t_point orig, t_vec dir)
{
	t_ray	ray;

	ray.origin = orig;
	ray.dir = dir;
	return (ray);
}
