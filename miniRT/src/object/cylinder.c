/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:31 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:45:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_cylinder	*cylinder(t_point point, double radius, double height, t_vec normal)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->point = point;
	cy->normal = normal;
	cy->radius = radius;
	cy->height = height;
	return (cy);
}

t_bool		hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)world->element;
	rec->albedo = world->albedo;
	if (cylinder_dis(cy, ray, rec) == FALSE)
		return (FALSE);
	
	return (TRUE);
}

t_bool		cylinder_dis(t_cylinder *cylinder, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	b;
	double	c;
	double	d;

	// cylinder->normal = vec_unit(cylinder->normal);
	t_vec A = vec_minus(
		ray->dir, vec_mul_num(vec_dot(ray->dir, cylinder->normal), cylinder->normal));
	t_vec B = vec_minus(
		vec_minus(ray->origin, cylinder->point),
		vec_mul_num(vec_dot(cylinder->point, cylinder->normal), cylinder->normal));
	a = vec_dot(A, A);
	b = vec_dot(vec_mul_num(2, A), B);
	c = vec_dot(B, B) - (cylinder->radius * cylinder->radius);
	d = (b * b) - (4 * a * c);
	rec->t = (-b - sqrt(d)) / (2 * a);
	if (d < 0)
		return (FALSE);
	if (rec->t < rec->tmin || rec->t > rec->tmax)
	{
		rec->t = (-b + sqrt(d)) / (2 * a);
		if (rec->t < rec->tmin || rec->t > rec->tmax)
		return (FALSE);
	}

	rec->p = ray_at(ray, rec->t);
	rec->normal = vec_unit(vec_minus(
		vec_minus(rec->p, cylinder->point),
		vec_mul_num(vec_dot(cylinder->normal, vec_minus(rec->p, cylinder->point)), cylinder->normal)));
	
	set_face_normal(ray, rec);


	// rec->t = (-b - sqrt(d)) / (2 * a);
	double pc2 = vec_length_2(vec_minus(rec->p, cylinder->point));
	double r2 = (cylinder->radius) * (cylinder->radius);
	double h2 = sqrt(pc2 - r2);
	if (h2 > cylinder->height){
		rec->t = (-b + sqrt(d)) / (2 * a);
		rec->p = ray_at(ray, rec->t);
		pc2 = vec_length_2(vec_minus(rec->p, cylinder->point));
		h2 = sqrt(pc2 - r2);
		if (h2 > cylinder->height)
			return (FALSE);
	}
	return (TRUE);
}
