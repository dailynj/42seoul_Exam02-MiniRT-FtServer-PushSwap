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
	t_cntl		cntl;
    // t_data		*image;
	t_color	pixel_color;
	int			i;
	int			j;
	double		u;
	double		v;

	if (argc != 2 && argc != 3)
		return (print_error("Error : Argument Error!\n"));
	cntl.mlx = mlx_init();
	if ((cntl.scene = scene_init()) == NULL)
		return (print_error("Error : scene_init 에러!\n"));
	if (parsing(&cntl, argv[1]) == 0)
		return (print_error("Error : Parsing Error!\n"));
	// printf("------------------------------------\n");
	// printf("\n<resolution>");
	// printf("\nR = %lf, %lf, %lf",
	// 		cntl.scene->canvas.width,
	// 		cntl.scene->canvas.height,
	// 		cntl.scene->canvas.aspect_ratio);
	// printf("\n\n<ambient>");
	// write(1, "##\n", 3);
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

	// // // write(1, "hi\n", 3);
	// // // while (1)
	// // // 	;
	// // cntl.scene->world = cntl.scene->world->next;
	// // printf("\npoint = %f", ((t_sphere*)(cntl.scene->world->element))->center.x);
	// // cntl.scene->world = cntl.scene->world->next;
	// // printf("\npoint = %f", ((t_sphere*)(cntl.scene->world->element))->center.x);
	// printf("\n------------------------------------\n");
	// write(1, "@@@@here@@@\n", 13);

	// printf("height = %f\n", ((t_cylinder *)(cntl.scene->world->element))->height);
	// printf("radius = %f\n", ((t_cylinder *)(cntl.scene->world->element))->radius);
	// printf("normal = %f %f %f\n", ((t_cylinder *)(cntl.scene->world->element))->normal.x
	// , ((t_cylinder *)(cntl.scene->world->element))->normal.y, ((t_cylinder *)(cntl.scene->world->element))->normal.z);
	// printf("point = %f %f %f\n", ((t_cylinder *)(cntl.scene->world->element))->point.x
	// , ((t_cylinder *)(cntl.scene->world->element))->point.y, ((t_cylinder *)(cntl.scene->world->element))->point.z);


    cntl.win = mlx_new_window(cntl.mlx, cntl.scene->canvas.width, cntl.scene->canvas.height, "NAJEONG World!");

	int idx = 0;
	if (!(cntl.image = (t_data *)malloc(cntl.scene->camera_num * sizeof(t_data))))
		print_error("Error : data malloc Fail!!!\n");
	printf("\n*** miniRT start ***\n");
	while (idx < cntl.scene->camera_num){
		cntl.image[idx].img = mlx_new_image(cntl.mlx, cntl.scene->canvas.width, cntl.scene->canvas.height);
		cntl.image[idx].addr = mlx_get_data_addr(cntl.image[idx].img, &cntl.image[idx].bits_per_pixel, &cntl.image[idx].line_length, &cntl.image[idx].endian);
		j = cntl.scene->canvas.height - 1;
		printf("make image\n");
		while (j >= 0)
		{
			i = 0;
			while (i < cntl.scene->canvas.width)
			{
				///printf("\ni, j = %d, %d", i, j);
				u = (double)i / (cntl.scene->canvas.width - 1);
				v = (double)j / (cntl.scene->canvas.height - 1);
				
				cntl.scene->ray = ray_primary(&cntl.scene->camera_arr[idx], u, v);
				pixel_color = ray_color(cntl.scene);
				//printf("pixel_color = %f, %f, %f", pixel_color.x, pixel_color.y, pixel_color.z);
				my_mlx_pixel_put(&cntl.image[idx], i, cntl.scene->canvas.height - 1 - j, write_color(0, pixel_color));
				++i;
			}
			--j;
		}
		idx++;
	}
	// mlx_put_image_to_window(cntl.mlx, cntl.win, cntl.image[cntl.scene->camera_idx].img, 0, 0);
	mlx_put_image_to_window(cntl.mlx, cntl.win, cntl.image[cntl.scene->camera_idx].img, 0, 0);
	mlx_key_hook(cntl.win, key_hook, &cntl);
	mlx_loop(cntl.mlx);
	// mlx_loop(cntl.mlx);
	
	return (0);
}
