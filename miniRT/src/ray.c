/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:00 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:32:48 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray			ray(t_point origin, t_vec dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = v_unit(dir);
	return (ray);
}

t_vec			ray_at(t_ray *ray, double t)
{
	t_vec	out;

	out.x = ray->origin.x + ray->dir.x * t;
	out.y = ray->origin.y + ray->dir.y * t;
	out.z = ray->origin.z + ray->dir.z * t;
	return (out);
}

t_ray			ray_primary(t_cam *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->orig;
	ray.dir = v_unit(v_minus(
		vec_add(vec_add(cam->left_bottom, v_mul_n(u,
							cam->horiz)),
				v_mul_n(v, cam->vertical)),
		cam->orig));
	return (ray);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_vec			ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	return (vec(0, 0, 0));
}
