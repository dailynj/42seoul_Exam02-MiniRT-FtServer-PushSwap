/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pyramid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:24:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 03:56:00 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void	world2object_pm(t_matrix44 *rotate, t_vec *offset, t_ray *ray)
{
	ray->origin = v_minus(ray->origin, *offset);
	ray->origin = m_mult_v(ray->origin, 1.0, rotate);
	ray->dir = m_mult_v(ray->dir, 0, rotate);
}

int			check_rotate_pyramid(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_ray			ray_w2o;
	t_pyramid		*pm;
	t_objects		obj_w2o;
	int				hit_result;
	t_vec			offset;

	if (obj->rotate != NULL)
	{
		obj_w2o = *obj;
		pm = obj->object;
		offset = pm->p;
		obj_w2o.object = pyramid(point(0, 0, 0), pm->len);
		ray_w2o = *r;
		world2object_pm(obj->rotate, &offset, &ray_w2o);
		hit_result = hit_pyramid(&ray_w2o, &obj_w2o, rec);
		object2world_rec(rec, &offset, obj->rotate, obj->rotate_normal);
	}
	else
		hit_result = hit_pyramid(r, obj, rec);
	return (hit_result);
}

static void	update_record(t_hit_record *tmp_rec, t_hit_record *rec, int *hit)
{
	*hit = TRUE;
	tmp_rec->t_max = tmp_rec->t;
	*rec = *tmp_rec;
}

int			hit_pyramid(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	t_pyramid		*pm;
	t_objects		o;
	int				hit_anything;
	int				i;

	i = 0;
	tmp_rec = *rec;
	hit_anything = FALSE;
	o = *obj;
	pm = obj->object;
	while (i < 4)
	{
		o.object = pm->tr[i];
		if (hit_triangle(r, &o, &tmp_rec))
			update_record(&tmp_rec, rec, &hit_anything);
		i++;
	}
	o.object = pm->sq;
	if (hit_square(r, &o, &tmp_rec))
		update_record(&tmp_rec, rec, &hit_anything);
	return (hit_anything);
}
