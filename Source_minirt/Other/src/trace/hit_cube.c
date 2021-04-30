/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:01:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 03:52:58 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int			hit_cube(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	t_objects		sq;
	t_cube			*cb;
	int				hit_anything;
	int				i;

	tmp_rec = *rec;
	hit_anything = FALSE;
	sq = *obj;
	cb = obj->object;
	i = -1;
	while (++i < 6)
	{
		sq.object = cb->sq[i];
		if (hit_square(r, &sq, &tmp_rec))
		{
			hit_anything = TRUE;
			tmp_rec.t_max = tmp_rec.t;
			*rec = tmp_rec;
		}
	}
	return (hit_anything);
}

static void	world2object_cb(t_matrix44 *rotate, t_vec *offset, t_ray *ray)
{
	ray->origin = v_minus(ray->origin, *offset);
	ray->origin = m_mult_v(ray->origin, 1.0, rotate);
	ray->dir = m_mult_v(ray->dir, 0, rotate);
}

static void	free_cube(t_cube *cb)
{
	int				i;

	i = -1;
	while (++i < 6)
		free(cb->sq[i]);
	free(cb);
}

int			check_rotate_cube(t_ray *r, t_objects *objs, t_hit_record *rec)
{
	t_ray			ray_w2o;
	t_cube			*cb;
	t_objects		obj_w2o;
	int				hit_result;
	t_vec			offset;

	if (objs->rotate != NULL)
	{
		obj_w2o = *objs;
		cb = objs->object;
		offset = cb->p;
		obj_w2o.object = cube(point(0, 0, 0), cb->len);
		ray_w2o = *r;
		world2object_cb(objs->rotate, &offset, &ray_w2o);
		hit_result = hit_cube(&ray_w2o, &obj_w2o, rec);
		object2world_rec(rec, &offset, objs->rotate, objs->rotate_normal);
		free_cube(obj_w2o.object);
	}
	else
		hit_result = hit_cube(r, objs, rec);
	return (hit_result);
}
