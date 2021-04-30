/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_parallel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 02:45:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 14:22:55 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int				check_parellel_shadow(t_ray *r, t_objects *objects)
{
	t_hit_record	rec;
	int				hit_anything;

	rec.t_min = 0.001;
	rec.t_max = v_len(r->dir);
	r->dir = v_normalize(r->dir);
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(r, objects, &rec))
			hit_anything = TRUE;
		objects = objects->next;
	}
	return (hit_anything);
}

static void		get_parallel_light_set(t_light_set *l, t_hit_record *rec,
										t_ray *r, t_parallel_light *pl)
{
	l->unit_norm = v_normalize(rec->normal);
	l->view_dir = v_multiply(r->dir, -1);
	l->light_dir = v_multiply(pl->dir, -1);
	l->to_light_ray = ray(v_plus(rec->p,
								v_multiply(rec->normal, 1e-4)), l->light_dir);
	l->unit_light_dir = v_normalize(l->light_dir);
	l->reflect_dir = reflect(v_multiply(l->unit_light_dir, -1), l->unit_norm);
}

t_color			phong_color_parallel(t_ray *r, t_parallel_light *pl,
			t_hit_record *rec, t_objects *objects_for_check)
{
	t_light_set		l;
	t_diffuse		diffuse;
	t_specular		specular;
	t_color			strength;

	get_parallel_light_set(&l, rec, r, pl);
	if (check_parellel_shadow(&l.to_light_ray, objects_for_check))
		return (color(0, 0, 0));
	diffuse = get_diffuse_strength(l, pl->albedo);
	specular = get_specular_strength(l, pl->albedo, diffuse);
	strength = v_plus(diffuse.strength, specular.strength);
	return (strength);
}
