/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:00:52 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 14:07:27 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int		hit_plane(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec	to_hit;
	t_plane	*plane;

	plane = (t_plane *)obj->object;
	denom = v_dot(plane->n, r->dir);
	if (fabs(denom) < 1e-6)
		return (FALSE);
	to_hit = v_minus(plane->point, r->origin);
	t = v_dot(to_hit, plane->n) / denom;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	get_record(rec, t, obj, r);
	rec->normal = plane->n;
	set_face_normal(*r, rec);
	return (TRUE);
}
