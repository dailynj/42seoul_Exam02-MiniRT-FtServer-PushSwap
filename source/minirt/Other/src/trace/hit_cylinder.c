/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:00:32 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/17 15:54:34 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void			get_cylinder_uv(t_hit_record *rec, t_cylinder *cylinder,
																	double len)
{
	double			phi;
	double			sines;

	phi = 0.0;
	if (is_aligned(cylinder->vec) == X)
		phi = atan2(-(rec->normal.y), rec->normal.z) + PI;
	else if (is_aligned(cylinder->vec) == Y)
		phi = atan2(-(rec->normal.z), rec->normal.x) + PI;
	else if (is_aligned(cylinder->vec) == Z)
		phi = atan2(-(rec->normal.x), rec->normal.y) + PI;
	rec->u = phi / (2 * PI);
	rec->v = len / cylinder->len;
	sines = sin(50 * rec->u) * sin(50 * rec->v);
}

static t_cy_set		get_cylinder_discriminant(t_cylinder *cylinder, t_ray *r)
{
	t_cy_set		cy;

	cy.delp = v_minus(r->origin, cylinder->p);
	cylinder->vec = v_normalize(cylinder->vec);
	cy.a = v_len_squared(v_minus(r->dir,
			v_multiply(cylinder->vec, v_dot(r->dir, cylinder->vec))));
	cy.b = v_dot(v_minus(r->dir, v_multiply(cylinder->vec,
				v_dot(r->dir, cylinder->vec))),
				v_minus(cy.delp, v_multiply(cylinder->vec,
				v_dot(cy.delp, cylinder->vec))));
	cy.c = v_len_squared(v_minus(cy.delp, v_multiply(cylinder->vec,
				v_dot(cy.delp, cylinder->vec))))
				- cylinder->radius * cylinder->radius;
	cy.discriminant = cy.b * cy.b - cy.a * cy.c;
	return (cy);
}

static	int			get_cylinder_far_hitpoint(t_cy_set *cy,
				t_ray *r, t_cylinder *cylinder)
{
	cy->root = (-cy->b + cy->sqrtd) / cy->a;
	cy->p = at(cy->root, *r);
	if ((cy->len = v_dot(v_minus(cy->p, cylinder->p), cylinder->vec)) < 0)
		return (FALSE);
	if (cy->len <= cylinder->len)
		cy->n = v_normalize(v_minus(cy->p,
				at(cy->len, ray(cylinder->p, cylinder->vec))));
	else
		return (FALSE);
	return (TRUE);
}

static	int			get_cylinder_hitpoint(t_cy_set *cy, t_hit_record *rec,
										t_ray *r, t_objects *obj)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)obj->object;
	if (cy->discriminant < 0)
		return (FALSE);
	cy->sqrtd = sqrt(cy->discriminant);
	cy->root = (-cy->b - cy->sqrtd) / cy->a;
	if (cy->root < rec->t_min || cy->root > rec->t_max)
		return (FALSE);
	cy->p = at(cy->root, *r);
	if (!(cy->len = v_dot(v_minus(cy->p, cylinder->p), cylinder->vec)))
		return (FALSE);
	if (cy->len <= cylinder->len && cy->len > 0)
		cy->n = v_normalize(v_minus(cy->p, at(cy->len, ray(cylinder->p,
			cylinder->vec))));
	else
	{
		if (hit_disc(r, obj, rec) == TRUE)
			return (TRUE);
		if (get_cylinder_far_hitpoint(cy, r, cylinder) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int					hit_cylinder(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_cylinder		*cylinder;
	t_cy_set		cy;

	cylinder = (t_cylinder *)obj->object;
	cy = get_cylinder_discriminant(cylinder, r);
	if (get_cylinder_hitpoint(&cy, rec, r, obj) == FALSE)
		return (FALSE);
	get_record(rec, cy.root, obj, r);
	rec->normal = cy.n;
	set_face_normal(*r, rec);
	if (is_aligned(cylinder->vec) != FALSE)
		get_cylinder_uv(rec, cylinder, cy.len);
	return (TRUE);
}
