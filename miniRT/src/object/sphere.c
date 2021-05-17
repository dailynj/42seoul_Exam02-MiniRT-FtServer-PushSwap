/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:42 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:45:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sphere	*sphere(t_point center, double radius)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	if (sphere_discriminant(world->element, ray, rec) == FALSE)
		return (FALSE);
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool		sphere_discriminant(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;

	t_vec oc = vec(ray->origin.x - sp->center.x,
					ray->origin.y - sp->center.y,
					ray->origin.z - sp->center.z);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_div(sp->radius, v_minus(rec->p, sp->center));
	return (TRUE);
}
