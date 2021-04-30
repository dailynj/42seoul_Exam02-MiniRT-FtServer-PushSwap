/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 02:47:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 14:23:03 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_color		check_texture(t_hit_record *rec)
{
	if (rec->obj->type == SP)
	{
		if (rec->texture->type == CHECK)
			return (checkerboard_uv(rec));
		else if (rec->texture->type == RAINBOW)
			return (rainbow(rec));
		else if (rec->texture->type == WAVE)
			return (wave(rec));
	}
	else if (rec->obj->type == SQ || rec->obj->type == CY
		|| rec->obj->type == CO || rec->obj->type == CU)
	{
		if (rec->texture->type == CHECK)
			return (checkerboard_uv(rec));
		if (rec->texture->type == RAINBOW)
			return (rainbow(rec));
	}
	else if (rec->obj->type == PL && rec->texture->type == CHECK)
		return (checkerboard(rec));
	return (rec->texture->albedo);
}

t_color		phong_color(t_ray *r, t_scene *scene, t_hit_record *rec)
{
	t_color			light_color;
	t_objects		*objects;
	t_objects		*obj_for_check;

	objects = scene->objs;
	light_color = scene->global.ambient;
	obj_for_check = objects;
	while (objects)
	{
		if (objects->type == SPOT_LIGHT)
			light_color = v_plus(light_color,
			phong_color_spot(r, objects->object, rec, obj_for_check));
		if (objects->type == PARELLEL_LIGHT)
			light_color = v_plus(light_color,
			phong_color_parallel(r, objects->object, rec, obj_for_check));
		objects = objects->next;
	}
	light_color = v_multiply_2(light_color, check_texture(rec));
	light_color = v_min(light_color, color(1.0, 1.0, 1.0));
	return (light_color);
}

t_color		ray_color(t_ray *r, t_scene *scene)
{
	t_hit_record	rec;

	rec.t_max = INFINITY;
	rec.t_min = 0.0001;
	if (hit(r, scene->objs, &rec))
		return (phong_color(r, scene, &rec));
	else
		return (color_background(r, scene, &rec));
}

t_color		ray_color_preview(t_ray *r, t_scene *scene, int light_on)
{
	t_hit_record	rec;

	rec.t_max = INFINITY;
	rec.t_min = 0.0001;
	if (hit(r, scene->objs, &rec))
	{
		if (light_on == ON)
			return (phong_color(r, scene, &rec));
		else if (light_on == OFF)
			return (check_texture(&rec));
	}
	else if (light_on == ON)
		return (color_background(r, scene, &rec));
	return (color(0, 0, 0));
}
