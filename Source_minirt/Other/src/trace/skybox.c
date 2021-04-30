/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:14:18 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:55:31 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static int		saturate_w(int w, int l, t_hit_record *rec)
{
	if (rec->normal.x == 1.0)
		w = l - w;
	else if (rec->normal.x == -1.0)
		w += 2 * l;
	else if (rec->normal.y == 1.0)
		w += l;
	else if (rec->normal.y == -1.0)
		w += l;
	else if (rec->normal.z == 1.0)
		w += l;
	else if (rec->normal.z == -1.0)
		w = 4 * l - w;
	return (w);
}

static int		saturate_h(int h, int l, t_hit_record *rec)
{
	if (rec->normal.x == 1.0)
		h += l;
	else if (rec->normal.x == -1.0)
		h += l;
	else if (rec->normal.y == 1.0)
		h = l - h;
	else if (rec->normal.y == -1.0)
		h += 2 * l;
	else if (rec->normal.z == 1.0)
		h += l;
	else if (rec->normal.z == -1.0)
		h += l;
	return (h);
}

t_color			albedo_skybox(t_hit_record *rec)
{
	int			wh[2];
	int			icolor;
	double		c_scale;
	t_data		*data;
	int			l;

	data = rec->texture->img;
	l = data->height / 3;
	wh[0] = (int)(rec->u * l);
	wh[1] = (int)(rec->v * l);
	saturate_min_max_int(wh[0], 0, l - 1);
	saturate_min_max_int(wh[1], 0, l - 1);
	wh[0] = saturate_w(wh[0], l, rec);
	wh[1] = saturate_h(wh[1], l, rec);
	c_scale = 1.0 / 255.0;
	wh[1] = data->height - wh[1] - 1;
	icolor = *(int *)(data->addr + (wh[1] * data->line_length
								+ wh[0] * (data->bits_per_pixel / 8)));
	return (color(c_scale * get_r(icolor),
					c_scale * get_g(icolor),
					c_scale * get_b(icolor)));
}

t_color			color_background(t_ray *r, t_scene *s, t_hit_record *rec)
{
	double		t;

	if (s->background == NULL)
	{
		t = 0.5 * (r->dir.y + 1);
		return (v_plus(v_multiply(color(1, 1, 1), 1.0 - t),
				v_multiply(color(0.5, 0.7, 1.0), t)));
	}
	else if (hit_cube(r, s->background, rec))
		return (albedo_skybox(rec));
	else
		return (color(0, 0, 0));
}
