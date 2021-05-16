/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:17 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:41:05 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_light	*light_point(t_vec light_origin, t_color light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = vec_mul_num(bright_ratio, light_color);
	light->bright_ratio = bright_ratio;
	return (light);
}

t_color	phong_lighting(t_scene *scene)
{
	t_color		light_color;
	t_object	*lights;

	light_color = scene->ambient;
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vec_add(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	return (vec_min(vec_mul(light_color, scene->rec.albedo), color(1.0, 1.0, 1.0)));
}

t_color	point_light_get(t_scene *scene, t_light *light)
{
	t_color	diffuse;
	t_vec	light_dir;
	t_color	specular;
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	spec;
	double	ksn;
	double	ks;
	double	light_len;
	t_ray	light_ray;

	double kd;
	light_dir = vec_minus(light->origin, scene->rec.p);
	light_len = vec_length(light_dir);
	light_dir = vec_unit(light_dir);
	light_ray = ray(vec_add(scene->rec.p, vec_mul_num(EPSILON, vec_unit(scene->rec.normal))), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color(0.0, 0.0, 0.0));
	kd = fmax(vec_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = vec_mul_num(kd, light->light_color);
	
	view_dir = vec_unit(vec_mul_num(-1, scene->ray.dir));
	reflect_dir = vec_unit(reflect(vec_mul_num(-1, light_dir), vec_unit(scene->rec.normal)));
	ksn = 100;
	ks = 0.7;
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = vec_mul_num(spec, vec_mul_num(ks, light->light_color));
	return (vec_min(vec(1.0, 1.0, 1.0), vec_add(diffuse, specular)));
}

t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_minus(v, vec_mul_num(vec_dot(v, n) * 2, n)));
}