/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:01:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 03:58:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void			get_cone_uv(t_hit_record *rec, t_cone *cone, double len)
{
	double		phi;
	double		sines;

	phi = 0.0;
	if (is_aligned(cone->axis) == X)
		phi = atan2(-(rec->normal.y), rec->normal.z) + PI;
	else if (is_aligned(cone->axis) == Y)
		phi = atan2(-(rec->normal.z), rec->normal.x) + PI;
	else if (is_aligned(cone->axis) == Z)
		phi = atan2(-(rec->normal.x), rec->normal.y) + PI;
	rec->u = phi / (2 * PI);
	rec->v = len / cone->height;
	sines = sin(50 * rec->u) * sin(50 * rec->v);
}

static t_co_set		get_cone_discriminant(t_cone *cone, t_ray *r)
{
	t_co_set	co;

	co.pa = cone->p;
	co.delp = v_minus(r->origin, co.pa);
	co.cosa = cos(deg_to_rad(cone->angle));
	co.sina = sin(deg_to_rad(cone->angle));
	co.a = co.cosa * co.cosa * v_len_squared(
		v_minus(r->dir, v_multiply(cone->axis, v_dot(r->dir, cone->axis))))
		- co.sina * co.sina
		* v_dot(r->dir, cone->axis) * v_dot(r->dir, cone->axis);
	co.b = co.cosa * co.cosa * v_dot(v_minus(r->dir,
		v_multiply(cone->axis, v_dot(r->dir, cone->axis))),
		v_minus(co.delp, v_multiply(cone->axis, v_dot(co.delp, cone->axis))))
		- co.sina * co.sina
		* v_dot(r->dir, cone->axis) * v_dot(co.delp, cone->axis);
	co.c = co.cosa * co.cosa * v_len_squared(v_minus(co.delp,
		v_multiply(cone->axis, v_dot(co.delp, cone->axis))))
		- co.sina * co.sina
		* v_dot(co.delp, cone->axis) * v_dot(co.delp, cone->axis);
	co.discriminant = co.b * co.b - co.a * co.c;
	return (co);
}

static	int			get_cone_hitpoint(t_co_set *co, t_hit_record *rec,
											t_ray *r, t_cone *cone)
{
	if (co->discriminant < 0)
		return (FALSE);
	co->sqrtd = sqrt(co->discriminant);
	co->root = (-co->b - co->sqrtd) / co->a;
	if (co->root < rec->t_min || co->root > rec->t_max)
		return (FALSE);
	co->p = at(co->root, *r);
	if ((co->len = v_dot(cone->axis, v_minus(co->p, cone->p))) < 0)
		return (FALSE);
	if (co->len <= cone->height && co->len > 0)
		co->n = v_normalize(v_minus(co->p, at(co->len,
							ray(cone->p, cone->axis))));
	else
	{
		co->root = (-co->b + co->sqrtd) / co->a;
		co->p = at(co->root, *r);
		if ((co->len = v_dot(cone->axis, v_minus(co->p, cone->p))) < 0)
			return (FALSE);
		if (co->len <= cone->height)
			co->n = v_normalize(v_minus(co->p, at(co->len,
							ray(cone->p, cone->axis))));
		else
			return (FALSE);
	}
	return (TRUE);
}

int					hit_cone(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_cone		*cone;
	t_co_set	co;

	cone = (t_cone *)obj->object;
	co = get_cone_discriminant(cone, r);
	if (get_cone_hitpoint(&co, rec, r, cone) == FALSE)
		return (FALSE);
	get_record(rec, co.root, obj, r);
	rec->normal = co.n;
	set_face_normal(*r, rec);
	if (is_aligned(cone->axis) != FALSE)
		get_cone_uv(rec, cone, co.len);
	return (TRUE);
}
