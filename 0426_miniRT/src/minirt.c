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
#include "../includes/minirt.h"

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>

//함수 선언부
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int prtimage();
int exit_hook();
int	key_hook(int keycode, t_cntl *cntl);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_color		pixel_color;
	t_cntl 		cntl;
	t_data 		image;
	double 		u;
	double 		v;

	t_scene		*scene = scene_init();

	cntl.mlx = mlx_init();
	cntl.win = mlx_new_window(cntl.mlx, scene->canvas.width, scene->canvas.height, "Hellow World!");
	image.img = mlx_new_image(cntl.mlx, scene->canvas.width, scene->canvas.height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	
	for (int j = scene->canvas.height-1; j >= 0; --j) {
		for (int i = 0; i < scene->canvas.width; ++i) {
			u = (double)(i) / (scene->canvas.width-1);
			v = (double)(j) / (scene->canvas.height-1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			my_mlx_pixel_put(&image, i, scene->canvas.height - 1 - j, write_color(0, pixel_color));\
		}
	}

	mlx_put_image_to_window(cntl.mlx, cntl.win, image.img, 0, 0);
	mlx_key_hook(cntl.win, key_hook, &cntl); // esc key press event
	mlx_hook(cntl.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(cntl.mlx);
	return (0);
}


// esc key press event
int	key_hook(int keycode, t_cntl *cntl)
{
	if(keycode == 53)
	{
		mlx_destroy_window(cntl->mlx, cntl->win);
		exit(0);
	}
	return (0);
}

// close button press event
int exit_hook()
{
	exit(0);
}