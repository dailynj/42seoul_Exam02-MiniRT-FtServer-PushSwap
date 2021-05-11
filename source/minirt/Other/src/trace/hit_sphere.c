/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:01:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:05:07 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void		get_sphere_uv(t_hit_record *rec)
{
	double		theta;
	double		phi;

	theta = acos(-(rec->normal.y));
	phi = atan2(-(rec->normal.z), rec->normal.x) + PI;
	rec->u = phi / (2 * PI);
	rec->v = theta / PI;
}

static t_sp_set	get_sphere_discriminant(t_sphere *sphere, t_ray *r)
{
	t_sp_set	sp;

	sp.oc = v_minus(r->origin, sphere->center);
	sp.a = v_dot(r->dir, r->dir);
	sp.b = v_dot(sp.oc, r->dir);
	sp.c = v_dot(sp.oc, sp.oc) - sphere->radius * sphere->radius;
	sp.discriminant = sp.b * sp.b - sp.a * sp.c;
	return (sp);
}

int				hit_sphere(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_sphere	*sphere;
	t_sp_set	sp;

	sphere = (t_sphere *)obj->object;
	sp = get_sphere_discriminant(sphere, r);
	if (sp.discriminant < 0)
		return (FALSE);
	else
	{
		sp.sqrtd = sqrt(sp.discriminant);
		sp.root = (-sp.b - sp.sqrtd) / sp.a;
		if (sp.root < rec->t_min || sp.root > rec->t_max)
		{
			sp.root = (-sp.b + sp.sqrtd) / sp.a;
			if (sp.root < rec->t_min || sp.root > rec->t_max)
				return (FALSE);
		}
	}
	get_record(rec, sp.root, obj, r);
	rec->normal = v_normalize(v_minus(rec->p, sphere->center));
	set_face_normal(*r, rec);
	get_sphere_uv(rec);
	return (TRUE);
}
