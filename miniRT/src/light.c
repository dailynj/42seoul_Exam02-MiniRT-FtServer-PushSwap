/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:17 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:44:23 by hyson            ###   ########.fr       */
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

	// light_color = color(0.0, 0.0, 0.0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
	light_color = scene->ambient;
	lights = scene->light;
	while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
	{
		if (lights->type == LIGHT_POINT)
			light_color = vec_add(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	return (vec_min(vec_mul(light_color, scene->rec.albedo), color(1.0, 1.0, 1.0)));

	//모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
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

	double kd; // diffuse의 강도
	light_dir = vec_minus(light->origin, scene->rec.p);
	light_len = vec_length(light_dir);
	light_dir = vec_unit(light_dir);
	light_ray = ray(vec_add(scene->rec.p, vec_mul_num(EPSILON, vec_unit(scene->rec.normal))), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color(0.0, 0.0, 0.0));
	// light_dir = vec_unit(vec_minus(light->origin, scene->rec.p)); //교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	// cosΘ는 Θ 값이 90도 일 때 0이고 Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체한다.
	kd = fmax(vec_dot(scene->rec.normal, light_dir),
				0.0); // (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	diffuse = vec_mul_num(kd, light->light_color);
	
	view_dir = vec_unit(vec_mul_num(-1, scene->ray.dir));
	reflect_dir = vec_unit(reflect(vec_mul_num(-1, light_dir), vec_unit(scene->rec.normal)));
	ksn = 100; // shininess value
	ks = 0.7; // specular strength
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
	// printf("spec = %lf\n", spec);
	specular = vec_mul_num(spec, vec_mul_num(ks, light->light_color));
	// return (vec(0, 0, 0));
	// printf("specular = %f %f %f\n", specular.x, specular.y, specular.z);
	// printf("diffuse = %f %f %f\n\n", diffuse.x, diffuse.y, diffuse.z);
	// specular = vec_mul_num(spec, vec_mul_num(ks, light->light_color));
	// printf("light->ligth_color = %f, %f, %f\n", light->light_color.x, light->light_color.y, light->light_color.z);
	// printf("diffuse = %f, %f, %f\n", diffuse.x, diffuse.y, diffuse.z);
	// printf("specular = %f, %f, %f\n\n", specular.x, specular.y, specular.z);
	// return (specular);
	return (vec_min(vec(1.0, 1.0, 1.0), vec_add(diffuse, specular)));
}

t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_minus(v, vec_mul_num(vec_dot(v, n) * 2, n)));
}
