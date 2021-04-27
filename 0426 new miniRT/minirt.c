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
	t_color		color;
	t_vars vars;
	t_data image;

	// Image
	double aspect_ratio = 16.0 / 9.0;
	int image_width = 1080;
	int image_height = (int)((double)image_width / aspect_ratio);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, image_width, image_height, "Hellow World!");
	image.img = mlx_new_image(vars.mlx, image_width, image_height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	
	// Camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	t_sphere sp = sphere(vec(0, 0, -1), 0.5);
	t_vec origin = vec(0, 0, 0); 
	t_vec horizontal = vec(viewport_width, 0, 0);
	t_vec vertical = vec(0, viewport_height, 0);
	t_vec lower_left_corner = vec(origin.x + (- horizontal.x / 2.0) + (-vertical.x / 2.0) + (0)
							       ,origin.y + (- horizontal.y / 2.0) + (-vertical.y / 2.0) + (0) 
							       ,origin.z + (- horizontal.z / 2.0) + (-vertical.z / 2.0) + (-focal_length));
	
	for (int j = image_height-1; j >= 0; --j) {
		for (int i = 0; i < image_width; ++i) {
			double u = (double)(i) / (image_width-1);
			double v = (double)(j) / (image_height-1);
			t_ray r;
			r.origin = vec(0, 0, 0);
			r.dir = vec(lower_left_corner.x + u*horizontal.x + v*vertical.x - origin.x,
			lower_left_corner.y + u*horizontal.y + v*vertical.y - origin.y,
			lower_left_corner.z + u*horizontal.z + v*vertical.z - origin.z);
			color = ray_color(r, &sp);
			my_mlx_pixel_put(&image, i, image_height - 1 - j, write_color(0, color));
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