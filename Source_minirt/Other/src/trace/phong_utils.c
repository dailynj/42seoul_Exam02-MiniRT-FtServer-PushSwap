/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:53:49 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 05:54:00 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_diffuse			get_diffuse_strength(t_light_set l, t_color albedo)
{
	t_diffuse		diffuse;

	diffuse.kd = fmax(v_dot(l.unit_norm, l.unit_light_dir), 0.0);
	diffuse.strength = v_multiply(albedo, diffuse.kd);
	return (diffuse);
}

t_specular			get_specular_strength(t_light_set l, t_color albedo,
															t_diffuse d)
{
	t_specular		specular;

	specular.ks = 0.5;
	specular.ksn = 256;
	specular.focus = pow(fmax(v_dot(l.view_dir, l.reflect_dir), 0.0),
															specular.ksn);
	specular.strength = v_multiply(v_multiply(albedo, d.kd), specular.focus);
	return (specular);
}

void				get_light_set(t_light_set *l, t_hit_record *rec, t_ray *r,
														t_spot_light *light)
{
	l->unit_norm = v_normalize(rec->normal);
	l->view_dir = v_multiply(r->dir, -1);
	l->light_dir = v_minus(light->p, rec->p);
	l->to_light_ray = ray(v_plus(rec->p,
								v_multiply(rec->normal, 1e-4)), l->light_dir);
	l->unit_light_dir = v_normalize(l->light_dir);
	l->reflect_dir = reflect(v_multiply(l->unit_light_dir, -1), l->unit_norm);
}
