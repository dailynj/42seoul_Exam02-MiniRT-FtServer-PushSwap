/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:53 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:45:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_triangle	*triangle(t_vec p1, t_vec p2, t_vec p3)
{
	t_triangle	*tr;

	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	tr->p1 = p1;
	tr->p2 = p2;
	tr->p3 = p3;
	tr->normal = v_unit(v_cr(v_minus(p2, p1), v_minus(p3, p1)));
	return (tr);
}

t_bool		hit_triangle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*tr;

	tr = world->element;
	rec->t = -vec_dot(v_minus(ray->origin, tr->p1), tr->normal) /
		vec_dot(tr->normal, ray->dir);
	rec->p = ray_at(ray, rec->t);
	if (rec->t < EPSILON || rec->t > rec->tmax)
		return (FALSE);
	if (check_tri(tr->p2, tr->p1, tr->p3, rec->p) == FALSE)
		return (FALSE);
	if (check_tri(tr->p3, tr->p2, tr->p1, rec->p) == FALSE)
		return (FALSE);
	if (check_tri(tr->p1, tr->p3, tr->p2, rec->p) == FALSE)
		return (FALSE);
	rec->normal = tr->normal;
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool		check_tri(t_vec a, t_vec b, t_vec c, t_vec point)
{
	t_vec	l_;
	t_vec	r_;
	t_vec	m_;

	l_ = v_minus(a, b);
	r_ = v_minus(c, b);
	m_ = v_minus(point, b);
	if (vec_dot(v_cr(l_, r_), v_cr(m_, r_)) < 0)
		return (FALSE);
	if (vec_dot(v_cr(r_, l_), v_cr(m_, l_)) < 0)
		return (FALSE);
	return (TRUE);
}
