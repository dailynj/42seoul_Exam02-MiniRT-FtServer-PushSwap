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

t_camera	*camera(t_point orig, double aspect_ratio)
{
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	cam->orig = orig;
	cam->viewport_w = 2.0;
	cam->viewport_h = cam->viewport_w / aspect_ratio;
	cam->focal_len = 1.0;
	cam->horizontal = vec(cam->viewport_w, 0, 0);
	cam->vertical = vec(0, cam->viewport_h, 0);
	cam->left_bottom =
		vec_minus(vec_minus(vec_minus(cam->orig, vec_div(2, cam->horizontal)),
							vec_div(2, cam->vertical)),
					vec(0, 0, 1.0));
	return (cam);
}

t_scene		*scene_init(void)
{
	t_scene	*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
	{
		printf("Error : Scene init Fail!!!\n");
		return (NULL);
	}
	scene->canvas.height = -1;
	scene->canvas.width = -1;
	scene->canvas.aspect_ratio = -1.0;
	scene->camera_arr = camera(point3(0, 0, 0), scene->canvas.aspect_ratio);
	scene->ambient = color(-1, -1, -1);
	scene->world = 0;
	scene->light = 0;
	scene->camera_num = 0;
	scene->camera_idx = 0;
	return (scene);
}
