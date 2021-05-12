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

// t_canvas	canvas(int	width, int height)
// {
// 	t_canvas canvas;

// 	canvas.width = width;
// 	canvas.height = height;
// 	canvas.aspect_ratio = (double)width / height;
// 	return (canvas);
// }

// t_camera	camera(t_canvas *canvas, t_point orig)
t_camera	*camera(t_point orig, double aspect_ratio)
{
	t_camera	*cam;

	// double		viewport_height;
	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	cam->orig = orig;
	cam->viewport_w = 2.0;
	cam->viewport_h = cam->viewport_w / aspect_ratio;
	cam->focal_len = 1.0; //고정
	cam->horizontal = vec(cam->viewport_w, 0, 0);
	cam->vertical = vec(0, cam->viewport_h, 0);
	cam->left_bottom =
		vec_minus(vec_minus(vec_minus(cam->orig, vec_div(2, cam->horizontal)),
							vec_div(2, cam->vertical)),
					vec(0, 0, 1.0)); // 1.0 은 focal len
	return (cam);
}

t_scene		*scene_init(void)
{
	t_scene	*scene;

	// t_object	*world;
	// t_object	*lights;
	// double		ka;
	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
	{
		printf("Error : Scene init Fail!!!\n");
		return (NULL);
	}
	// scene->canvas = canvas(800, 450);
	// scene->camera_arr = camera(point3(0, 0, 0), scene->canvas.aspect_ratio);
	// world = object(PL, plane(point3(-5, -2, -5), vec(0, 1, 0)), color(140.0/256, 227.0/256, 61.0/256)); // 아무것도 안찍히는 초기값
	// oadd(&world, object(SQ, square(point3(-3, 0, -3), vec(1, 1, 1), 1), color(0, 0, 0)));
	// oadd(&world, object(CY, cylinder(point3(2, 0, -10), vec(0, 1, 0), 1, 3), color(73.0/256, 217.0/256, 220.0/256)));
	// oadd(&world, object(PL, plane(point3(-5, -2, -5), vec(0, 1, 0)), color(140.0/256, 227.0/256, 61.0/256)));
	// oadd(&world, object(TR, triangle(point3(2, 1, -4), point3(3, 1, -3), point3(3, 2, -5)), color(0, 0, 1)));
	// scene->world = world;
	// lights = object(LIGHT_POINT, light_point(point3(0, 5, 0), color(0, 0, 0),
	// 0.5), color(0, 0, 0)); // 더미 albedo oadd(&lights, object(LIGHT_POINT,
	// light_point(point3(0, 5, 0), color(1, 1, 1), 0.5), color(0, 0, 0))); scene->light
	// = lights; ka = 0.3; scene->ambient = vec_mul_num(ka, color(1,1,1));
	scene->canvas.height = -1;
	scene->canvas.width = -1;
	scene->canvas.aspect_ratio = -1.0; // 구조체에서 없앴음
	// cam_list 로 변경해야됨
	scene->camera_arr = camera(point3(0, 0, 0), scene->canvas.aspect_ratio);
	scene->ambient = color(-1, -1, -1);
	scene->world = 0;
	scene->light = 0;
	return (scene);
}
