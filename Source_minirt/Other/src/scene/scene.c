/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:46:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:26:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void			scene_init(t_scene *scene)
{
	scene->global.ambient = color(0, 0, 0);
	scene->objs = NULL;
	scene->cam_list = NULL;
	scene->cam_onair = NULL;
	scene->background = NULL;
}

t_camera		*cam_init(t_point lookfrom, t_vec lookdir, double hfov)
{
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		malloc_error();
	cam->origin = lookfrom;
	cam->dir = lookdir;
	cam->hfov = hfov;
	return (cam);
}

void			set_cam(t_camera *cam, t_scene *scene)
{
	double		theta;
	double		half_width;
	double		viewport_height;
	double		viewport_width;
	t_cam_ray	r;

	if (cam->dir.x == 0 && cam->dir.z == 0)
		cam->dir.z = 1e-6;
	r.vup = vec(0.0, 1.0, 0.0);
	theta = deg_to_rad(cam->hfov);
	half_width = tan(theta / 2.0);
	viewport_width = 2.0 * half_width;
	viewport_height = viewport_width / scene->canvas.ratio;
	r.w = v_normalize(v_multiply(cam->dir, -1));
	r.u = v_normalize(v_cross(r.vup, r.w));
	r.v = v_cross(r.w, r.u);
	cam->horizontal = v_multiply(r.u, viewport_width);
	cam->vertical = v_multiply(r.v, viewport_height);
	cam->leftbottom = v_minus(v_minus(v_minus(cam->origin,
	v_multiply(cam->horizontal, 0.5)), v_multiply(cam->vertical, 0.5)), r.w);
}
