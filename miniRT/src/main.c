/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:49:55 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:44:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	// t_cntl	cntl;
	// t_data	image;
	// double	u;
	// double	v;
	// t_color	pixel_color;

	if (argc != 2 && argc != 3)
		return (print_error("Error : Argument Error!\n"));
	// cntl.mlx = mlx_init();
	// if ((cntl.scene = scene_init()) == NULL)
	// 	return (print_error("Error : scene_init 에러!\n"));
	// if (parsing(&cntl, argv[1]) == 0)
	// 	return (print_error("Error : Parsing Error!\n"));
	// printf("------------------------------------\n");
	// printf("\n<resolution>");
	// printf("\nR = %lf, %lf, %lf",
	// 		cntl.scene->canvas.width,
	// 		cntl.scene->canvas.height,
	// 		cntl.scene->canvas.aspect_ratio);
	// printf("\n\n<ambient>");
	// printf("\nA = color(%lf, %lf, %lf)",
	// 		cntl.scene->ambient.x,
	// 		cntl.scene->ambient.y,
	// 		cntl.scene->ambient.z);
	// //카메라 0번 만 출력
	// printf("\n\n<camera>");
	// printf("\nc = xyz(%lf, %lf, %lf)",
	// 		cntl.scene->camera_arr[0].orig.x,
	// 		cntl.scene->camera_arr[0].orig.y,
	// 		cntl.scene->camera_arr[0].orig.z);
	// printf("\n  = nor(%lf, %lf, %lf)",
	// 		cntl.scene->camera_arr[0].normal.x,
	// 		cntl.scene->camera_arr[0].normal.y,
	// 		cntl.scene->camera_arr[0].normal.z);
	// printf("\n    width = %lf", cntl.scene->camera_arr[0].viewport_w);
	// printf("\n    height = %lf", cntl.scene->camera_arr[0].viewport_h);
	// printf("\n    focal_len = %lf\n", cntl.scene->camera_arr[0].focal_len);
	
	// // cntl.scene->light = cntl.scene->light->next;

	// write(1, "\n\n<light>", 9);
	// printf("\nl = xyz(%f, %f, %f)",
	// 		((t_light *)(cntl.scene->light->element))->origin.x,
	// 		((t_light *)(cntl.scene->light->element))->origin.y,
	// 		((t_light *)(cntl.scene->light->element))->origin.z);
	// printf("\n    light_color = (%lf, %lf, %lf)",
	// 		((t_light *)(cntl.scene->light->element))->light_color.x,
	// 		((t_light *)(cntl.scene->light->element))->light_color.y,
	// 		((t_light *)(cntl.scene->light->element))->light_color.z);
	// printf("\n    bright_ratio = %f", ((t_light *)(cntl.scene->light->element))->bright_ratio);

	// // write(1, "hi\n", 3);
	// // while (1)
	// // 	;
	// // cntl.scene->world = cntl.scene->world->next;
	// // printf("\npoint = %f", ((t_sphere*)(cntl.scene->world->element))->center.x);
	// // cntl.scene->world = cntl.scene->world->next;
	// // printf("\npoint = %f", ((t_sphere*)(cntl.scene->world->element))->center.x);
	// printf("\n------------------------------------\n");
	// write(1, "@@@@here@@@\n", 13);



	(void) argv[1];
	t_cntl		vars;
    t_data		image;
	t_color	pixel_color;
	int			i;
	int			j;
	double		u;
	double		v;
	// t_scene		*scene;

	(void)argc;
	// scene = (t_scene *)malloc(sizeof(t_scene));
	vars.scene = scene_init();
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, vars.scene->canvas.width, vars.scene->canvas.height, "SEUNGOH World!");
    image.img = mlx_new_image(vars.mlx, vars.scene->canvas.width, vars.scene->canvas.height);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	j = vars.scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < vars.scene->canvas.width)
		{
			u = (double)i / (vars.scene->canvas.width - 1);
			v = (double)j / (vars.scene->canvas.height - 1);
			vars.scene->ray = ray_primary(&vars.scene->camera_arr[0], u, v);
			pixel_color = ray_color(vars.scene);
			my_mlx_pixel_put(&image, i, vars.scene->canvas.height - 1 - j, write_color(0, pixel_color));
			++i;
		}
		--j;
	}
    mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    write(1, "\n\n\n\nhihihihihihi\n\n\n", 19);
	return (0);

	// cntl.win = mlx_new_window(
	// 	cntl.mlx, (int)cntl.scene->canvas.width, (int)cntl.scene->canvas.height, "Najeong World!");
	// write(1, "@@@@here@@@\n", 13);
	// image.img =
	// 	mlx_new_image(cntl.mlx, (int)cntl.scene->canvas.width, (int)cntl.scene->canvas.height); // 이미지 객체 생성
	// write(1, "@@@@here@@@\n", 13);
	// image.addr = mlx_get_data_addr(
	// 	image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	// write(1, "@@@@here@@@\n", 13);
	// for (int j = (int)cntl.scene->canvas.height - 1; j >= 0; --j)
	// {
	// 	for (int i = 0; i < (int)cntl.scene->canvas.width; ++i)
	// 	{
	// 		u = (double)(i) / (cntl.scene->canvas.width - 1);  
	// 		v = (double)(j) / (cntl.scene->canvas.height - 1);
	// 		printf("u, v = %lf, %lf", u, v);
	// 		cntl.scene->ray = ray_primary(&cntl.scene->camera_arr[0], u, v); // 0번째 카메라
	// 		pixel_color = ray_color(cntl.scene);
	// 		my_mlx_pixel_put(
	// 			&image, i, cntl.scene->canvas.height - 1 - j, write_color(0, pixel_color));
	// 		// void 포인터에 좌표를 찍는다 image pointer
	// 	}
	// }
	// write(1, "@@@@here@@@\n", 13);
	// mlx_put_image_to_window(cntl.mlx, cntl.win, image.img, 0, 0);
	// mlx_key_hook(cntl.win, key_hook, &cntl); // esc key press event
	// mlx_hook(cntl.win, 17, 0, exit_hook, 0); // close button press event
	// mlx_loop(cntl.mlx);
	return (0);
}
