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

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// esc key press event
int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == KEY_ESC)
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

int main()
{
	t_data	image; // 이미지의 정보를 나타내는 변수들을 저장한 구조체
	t_vars	vars; // mlx포인터와 생성할 window 포인터를 가지는 구조체
	
	double aspect_ratio = 16.0 / 9.0;
	int image_width = 400;
	int image_height = (image_width / aspect_ratio);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, image_width, image_height, "Hellow World!");
	image.img = mlx_new_image(vars.mlx, image_width, image_height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	
	// Image

	// Camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	t_vec origin = vec3(0, 0, 0); 
	t_vec horizontal = vec3(viewport_width, 0, 0);
	t_vec vertical = vec3(0, viewport_height, 0);
	t_vec lower_left_corner = vec3(origin.x + (- horizontal.x / 2.0) + (-vertical.x / 2.0) + (0)
							       ,origin.y + (- horizontal.y / 2.0) + (-vertical.y / 2.0) + (0) 
							       ,origin.z + (- horizontal.z / 2.0) + (-vertical.z / 2.0) + (-focal_length));
	//t_vec lower_left_corner = minus_two_vector(minus_two_vector(minus_two_vector(origin, div_num_vector(2.0, horizontal)), div_num_vector(2, vertical)), vec3(0, 0, focal_length));
	
	// Render
	for (int j = image_height - 1; j >= 0; --j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			double u = (double)i / (image_width - 1);
			double v = (double)j / (image_height - 1);
			t_ray r;
			r.orig = vec3(0, 0, 0); // 3차원상의 정점 좌표
			r.dir = vec3(lower_left_corner.x + u * horizontal.x + v * vertical.x - origin.x,
						 lower_left_corner.y + u * horizontal.y + v * vertical.y - origin.y,
						 lower_left_corner.z + u * horizontal.z + v * vertical.z - origin.z);
			// t_ray r = ray(origin, (minus_two_vector(plus_two_vector(plus_two_vector(lower_left_corner, mul_num_vector(u, horizontal)), mul_num_vector(v, vertical)), origin)));
			t_color pixel_color = color(ray_color(r).x, ray_color(r).y, ray_color(r).z);
			// printf("color : %d\n", write_color(0, pixel_color));
			my_mlx_pixel_put(&image, i, j, write_color(0, pixel_color));
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);
	return (0);
}
