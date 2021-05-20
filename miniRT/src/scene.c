/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:49 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:59 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_cam		*camera(t_point orig, double aspect_ratio)
{
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	cam->orig = orig;
	cam->vp_w = 2.0;
	cam->vp_h = cam->vp_w / aspect_ratio;
	cam->focal_len = 1.0;
	cam->horiz = vec(cam->vp_w, 0, 0);
	cam->vertical = vec(0, cam->vp_h, 0);
	cam->left_bottom =
		v_minus(v_minus(v_minus(cam->orig, vec_div(2, cam->horiz)),
							vec_div(2, cam->vertical)),
					vec(0, 0, 1.0));
	return (cam);
}

t_scene		*scene_init(void)
{
	t_scene	*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canv.heig = -1;
	scene->canv.wid = -1;
	scene->canv.aspect_ratio = -1.0;
	scene->ambient = color(-1, -1, -1);
	scene->world = 0;
	scene->light = 0;
	scene->c_num = 0;
	scene->camera_idx = 0;
	return (scene);
}
