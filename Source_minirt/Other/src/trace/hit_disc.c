/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_disc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 04:09:02 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/17 15:59:04 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static	int			get_disc_hitpoint(t_disc_set *di, t_cylinder *cy,
										t_ray *r, t_hit_record *rec)
{
	if (fabs(di->denom) < 1e-6)
		return (FALSE);
	if (cy->vec.z < 0)
	{
		di->to_hit = v_minus(cy->p, r->origin);
		di->t = v_dot(di->to_hit, cy->vec) / di->denom;
	}
	else
	{
		di->to_hit = v_minus(v_plus(cy->p,
					v_multiply(cy->vec, cy->len)), r->origin);
		di->t = v_dot(di->to_hit, cy->vec) / di->denom;
	}
	if (di->t < rec->t_min || di->t > rec->t_max)
		return (FALSE);
	di->p = at(di->t, *r);
	return (TRUE);
}

int					hit_disc(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_cylinder	*cylinder;
	t_disc_set	di;

	cylinder = (t_cylinder *)obj->object;
	di.denom = v_dot(cylinder->vec, r->dir);
	if (get_disc_hitpoint(&di, cylinder, r, rec) == FALSE)
		return (FALSE);
	if (cylinder->vec.z < 0)
	{
		if (v_len_squared(v_minus(cylinder->p, di.p))
				> cylinder->radius * cylinder->radius)
			return (FALSE);
	}
	else
	{
		if (v_len_squared(v_minus(v_plus(cylinder->p,
			v_multiply(cylinder->vec, cylinder->len)), di.p))
					> cylinder->radius * cylinder->radius)
			return (FALSE);
	}
	rec->normal = cylinder->vec;
	get_record(rec, di.t, obj, r);
	set_face_normal(*r, rec);
	return (TRUE);
}
