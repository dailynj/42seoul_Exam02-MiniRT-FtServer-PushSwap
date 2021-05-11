/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:02:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:07:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static t_vec	world2object_sq(t_matrix44 *rotate, t_square *sq, t_ray *r)
{
	t_vec			offset;

	offset = sq->p;
	r->origin = v_minus(r->origin, offset);
	sq->p = v_minus(sq->p, offset);
	sq->min = v_minus(sq->min, offset);
	sq->max = v_minus(sq->max, offset);
	r->origin = m_mult_v(r->origin, 1.0, rotate);
	r->dir = m_mult_v(r->dir, 0, rotate);
	return (offset);
}

int				check_rotate_square(t_ray *ray, t_objects *obj,
												t_hit_record *rec)
{
	t_ray			ray_w2o;
	t_square		sq_w2o;
	t_objects		obj_w2o;
	int				hit_result;
	t_vec			offset;

	if (obj->rotate != NULL)
	{
		obj_w2o = *obj;
		sq_w2o = *(t_square *)obj->object;
		obj_w2o.object = &sq_w2o;
		ray_w2o = *ray;
		offset = world2object_sq(obj->rotate, &sq_w2o, &ray_w2o);
		hit_result = hit_square(&ray_w2o, &obj_w2o, rec);
		object2world_rec(rec, &offset, obj->rotate, obj->rotate_normal);
	}
	else
		hit_result = hit_square(ray, obj, rec);
	return (hit_result);
}

static void		get_square_uv(t_hit_record *rec, t_square *sq, double len)
{
	double			inverted;

	inverted = 1 / len;
	if (is_aligned(sq->n) == X)
	{
		rec->u = (rec->p.z - sq->min.z) * inverted;
		rec->v = (rec->p.y - sq->min.y) * inverted;
	}
	else if (is_aligned(sq->n) == Y)
	{
		rec->u = (rec->p.x - sq->min.x) * inverted;
		rec->v = (rec->p.z - sq->min.z) * inverted;
	}
	else if (is_aligned(sq->n) == Z)
	{
		rec->u = (rec->p.x - sq->min.x) * inverted;
		rec->v = (rec->p.y - sq->min.y) * inverted;
	}
}

static int		is_inside_square(t_square *square, t_point p)
{
	if (is_aligned(square->n) == X)
	{
		if (!(fabs(p.y - square->p.y) <= (square->side_len / 2.0)
			&& fabs(p.z - square->p.z) <= (square->side_len / 2.0)))
			return (FALSE);
	}
	else if (is_aligned(square->n) == Y)
	{
		if (!(fabs(p.z - square->p.z) <= (square->side_len / 2.0)
			&& fabs(p.x - square->p.x) <= (square->side_len / 2.0)))
			return (FALSE);
	}
	else if (is_aligned(square->n) == Z)
	{
		if (!(fabs(p.y - square->p.y) <= (square->side_len / 2.0)
			&& fabs(p.x - square->p.x) <= (square->side_len / 2.0)))
			return (FALSE);
	}
	return (TRUE);
}

int				hit_square(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	double			root;
	t_point			p;
	t_square		*square;

	square = (t_square *)obj->object;
	root = v_dot(v_minus(square->p, r->origin), square->n)
							/ v_dot(square->n, r->dir);
	if (root < 0 || root < rec->t_min || root > rec->t_max)
		return (0);
	p = at(root, *r);
	if (is_inside_square(square, p) == FALSE)
		return (FALSE);
	get_record(rec, root, obj, r);
	rec->normal = square->n;
	set_face_normal(*r, rec);
	get_square_uv(rec, square, square->side_len);
	return (TRUE);
}
