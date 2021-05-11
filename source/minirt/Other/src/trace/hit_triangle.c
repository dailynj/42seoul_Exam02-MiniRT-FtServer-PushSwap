/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:59:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:08:28 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int			hit_triangle(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	double		t;
	double		denom;
	t_point		to_hit;
	t_point		p;
	t_triangle	*triangle;

	triangle = (t_triangle *)obj->object;
	denom = v_dot(triangle->n, r->dir);
	if (fabs(denom) < 1e-6)
		return (FALSE);
	to_hit = v_minus(triangle->p[0], r->origin);
	t = v_dot(to_hit, triangle->n) / denom;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = at(t, *r);
	if (!(is_inside(triangle->p[0], triangle->p[1], triangle->p[2], p)))
		return (FALSE);
	get_record(rec, t, obj, r);
	rec->normal = triangle->n;
	set_face_normal(*r, rec);
	return (TRUE);
}
