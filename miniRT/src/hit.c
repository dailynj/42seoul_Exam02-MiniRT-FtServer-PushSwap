/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:49:45 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:32:24 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
	else if (world->type == PL)
		hit_result = hit_plane(world, ray, rec);
	else if (world->type == SQ)
		hit_result = hit_square(world, ray, rec);
	else if (world->type == TR)
		hit_result = hit_triangle(world, ray, rec);
	else if (world->type == CY)
		hit_result = hit_cylinder(world, ray, rec);
	return (hit_result);
}

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = vec_dot(ray->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal :
					v_mul_n(-1, rec->normal);
}
