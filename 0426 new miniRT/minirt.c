/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:46:09 by najlee            #+#    #+#             */
/*   Updated: 2021/04/09 20:04:21 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>

#define SP 0 //지워야 할거...ㅠ

//함수 선언부
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int prtimage();
int exit_hook();
int	key_hook(int keycode, t_vars *vars);

// main function!
int main()
{
	prtimage();
	return (0);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int prtimage()
{
	t_color		pixel_color;
	t_vars vars;
	t_data image;
	double u;
	double v;

	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;

	canv = canvas(1080, 900);
	cam = camera(&canv, point3(0, 0, 0));

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, canv.width, canv.height, "Hellow World!");
	image.img = mlx_new_image(vars.mlx, canv.width, canv.height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	
	// // Camera
	// double viewport_height = 2.0;
	// double viewport_width = aspect_ratio * viewport_height;
	// double focal_length = 1.0;

	t_object *world;
	world = object(SP, sphere(point3(-2, 0, -5), 2)); // world 에 구1 추가
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2))); // world 에 구2 추가
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990))); // world 에 구3 추가

	t_vec origin = vec(0, 0, 0); 
	t_vec horizontal = vec(cam.viewport_w, 0, 0);
	t_vec vertical = vec(0, cam.viewport_h, 0);
	t_vec lower_left_corner = vec(origin.x + (- horizontal.x / 2.0) + (-vertical.x / 2.0) + (0)
							       ,origin.y + (- horizontal.y / 2.0) + (-vertical.y / 2.0) + (0) 
							       ,origin.z + (- horizontal.z / 2.0) + (-vertical.z / 2.0) + (-cam.focal_len));
	
	for (int j = canv.height-1; j >= 0; --j) {
		for (int i = 0; i < canv.width; ++i) {
			u = (double)(i) / (canv.width-1);
			v = (double)(j) / (canv.height-1);
			ray = ray_primary(&cam, u, v);

			ray.dir = vec(lower_left_corner.x + u*horizontal.x + v*vertical.x - origin.x,
			lower_left_corner.y + u*horizontal.y + v*vertical.y - origin.y,
			lower_left_corner.z + u*horizontal.z + v*vertical.z - origin.z);
			pixel_color = ray_color(ray, world);
			// write_color(pixel_color);
			my_mlx_pixel_put(&image, i, canv.height - 1 - j, write_color(0, pixel_color));
			//ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
		}
	}

	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);
	return (0);
}


// esc key press event
int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

// close button press event
int exit_hook()
{
	exit(0);
}