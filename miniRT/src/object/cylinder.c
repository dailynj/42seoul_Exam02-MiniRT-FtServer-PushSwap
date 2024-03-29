/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:31 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 14:17:09 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_cylinder	*cylinder(t_point point, double radius, double heig, t_vec normal)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->point = point;
	cy->normal = normal;
	cy->radius = radius;
	cy->heig = heig;
	return (cy);
}

t_bool		hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)world->element;
	if (cylinder_discriminant(cylinder, ray, rec) == FALSE)
		return (FALSE);
	rec->p = ray_at(ray, rec->t);
	rec->normal = v_unit(v_minus(v_minus(rec->p, cylinder->point),
			v_mul_n(vec_dot(cylinder->normal, v_minus(rec->p, cylinder->point)),
			cylinder->normal)));
	rec->albedo = world->albedo;
	if (!cylinder_heig_check(cylinder, ray, rec))
		return (FALSE);
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool		cylinder_discriminant(t_cylinder *cylinder,
										t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = vec_length_2(v_minus(ray->dir, v_mul_n(
		vec_dot(cylinder->normal, ray->dir), cylinder->normal)));
	b = vec_dot(v_minus(ray->dir, v_mul_n(
		vec_dot(cylinder->normal, ray->dir), cylinder->normal)),
		v_minus(v_minus(ray->origin, cylinder->point),
		v_mul_n(vec_dot(cylinder->normal,
		v_minus(ray->origin, cylinder->point)), cylinder->normal)));
	c = vec_length_2(v_minus(v_minus(ray->origin, cylinder->point),
		v_mul_n(vec_dot(cylinder->normal,
		v_minus(ray->origin, cylinder->point)), cylinder->normal))) -
		cylinder->radius * cylinder->radius;
	d = b * b - a * c;
	rec->t = (-b - sqrt(d)) / a;
	rec->t2 = (-b + sqrt(d)) / a;
	if (d < 0)
		return (FALSE);
	if (rec->t < rec->tmin || rec->t > rec->tmax)
		if (rec->t2 < rec->tmin || rec->t2 > rec->tmax)
			return (FALSE);
	return (TRUE);
}

t_bool		cylinder_heig_check(t_cylinder *cylinder,
							t_ray *ray, t_hit_record *rec)
{
	double		h;

	h = vec_length_2(v_minus(rec->p, cylinder->point)) -
			cylinder->radius * cylinder->radius;
	if (sqrt(h) > cylinder->heig)
	{
		rec->p = ray_at(ray, rec->t2);
		h = vec_length_2(v_minus(rec->p, cylinder->point)) -
			cylinder->radius * cylinder->radius;
		rec->normal = v_unit(vec_div(cylinder->radius,
			v_minus(v_minus(rec->p, cylinder->point),
		v_mul_n(vec_dot(cylinder->normal, v_minus(rec->p,
			cylinder->point)), cylinder->normal))));
		if (sqrt(h) > cylinder->heig)
			return (FALSE);
	}
	return (TRUE);
}
