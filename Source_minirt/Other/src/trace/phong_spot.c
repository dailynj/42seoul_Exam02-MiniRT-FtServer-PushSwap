/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 02:44:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 05:53:43 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int		check_shadow(t_ray *ray, t_objects *objects)
{
	t_hit_record	rec;
	int				hit_anything;

	rec.t_min = 0.001;
	rec.t_max = v_len(ray->dir);
	ray->dir = v_normalize(ray->dir);
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(ray, objects, &rec))
			hit_anything = TRUE;
		objects = objects->next;
	}
	return (hit_anything);
}

t_color	phong_color_spot(t_ray *r, t_spot_light *light, t_hit_record *rec,
												t_objects *objects_for_check)
{
	t_diffuse		diffuse;
	t_specular		specular;
	t_color			strength;
	t_light_set		l;
	t_color			albedo;

	l.lux = 50;
	get_light_set(&l, rec, r, light);
	if (check_shadow(&l.to_light_ray, objects_for_check))
		return (color(0, 0, 0));
	albedo = v_multiply(light->color, l.lux * light->brightness);
	diffuse = get_diffuse_strength(l, albedo);
	specular = get_specular_strength(l, albedo, diffuse);
	strength = v_plus(diffuse.strength, specular.strength);
	l.distance_attenuation = 1.0 / v_len_squared(v_minus(light->p, rec->p));
	return (v_multiply(strength, l.distance_attenuation));
}
