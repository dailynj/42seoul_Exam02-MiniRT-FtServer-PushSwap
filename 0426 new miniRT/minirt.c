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

	t_scene		*scene = scene_init();

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, scene->canvas.width, scene->canvas.height, "Hellow World!");
	image.img = mlx_new_image(vars.mlx, scene->canvas.width, scene->canvas.height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	
	// // Camera
	// double viewport_height = 2.0;
	// double viewport_width = aspect_ratio * viewport_height;
	// double focal_length = 1.0;

	// t_vec origin = vec(0, 0, 0); 
	// t_vec horizontal = vec(scene->camera.viewport_w, 0, 0);
	// t_vec vertical = vec(0, scene->camera.viewport_h, 0);
	// t_vec lower_left_corner = vec(origin.x + (- horizontal.x / 2.0) + (-vertical.x / 2.0) + (0)
	// 						       ,origin.y + (- horizontal.y / 2.0) + (-vertical.y / 2.0) + (0) 
	// 						       ,origin.z + (- horizontal.z / 2.0) + (-vertical.z / 2.0) + (-scene->camera.focal_len));
	
	for (int j = scene->canvas.height-1; j >= 0; --j) {
		for (int i = 0; i < scene->canvas.width; ++i) {
			u = (double)(i) / (scene->canvas.width-1);
			v = (double)(j) / (scene->canvas.height-1);
			scene->ray = ray_primary(&scene->camera, u, v);

			// scene->ray.dir = vec(lower_left_corner.x + u*horizontal.x + v*vertical.x - origin.x,
			// lower_left_corner.y + u*horizontal.y + v*vertical.y - origin.y,
			// lower_left_corner.z + u*horizontal.z + v*vertical.z - origin.z);
			pixel_color = ray_color(scene);

			// write_color(pixel_color);
			my_mlx_pixel_put(&image, i, scene->canvas.height - 1 - j, write_color(0, pixel_color));
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