#include "mlx.h"
#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_cntl		cntl;
	// t_data		image;

	if (argc != 2 && argc != 3)
	{
		printf("Error : Argument Error!\n");
		return (0);
	}
	cntl.mlx = mlx_init();
	if ((cntl.scene = scene_init()) == NULL)
	{
		printf("Error : scene_init 에러!\n");
		return (0);
	}
	if (parsing(&cntl, argv[1]) == 0)
	{
		printf("Error : Parsing Error!\n");
		return (0);
	}
	printf("------------------------------------\n");
	printf("\nR = %d, %d, %lf", cntl.scene->canvas.width, cntl.scene->canvas.height, cntl.scene->canvas.aspect_ratio);
	printf("\nA = color(%lf, %lf, %lf)", cntl.scene->ambient.x, cntl.scene->ambient.y, cntl.scene->ambient.z);
	//카메라 0번 만 출력
	printf("\nc = xyz(%lf, %lf, %lf)", cntl.scene->camera_arr[0].orig.x, cntl.scene->camera_arr[0].orig.y, cntl.scene->camera_arr[0].orig.z);
	printf("\n  = nor(%lf, %lf, %lf)", cntl.scene->camera_arr[0].normal.x, cntl.scene->camera_arr[0].normal.y, cntl.scene->camera_arr[0].normal.z);
	printf("\n    width = %lf", cntl.scene->camera_arr[0].viewport_w);
	printf("\n    height = %lf", cntl.scene->camera_arr[0].viewport_h);
	printf("\n    focal_len = %lf\n", cntl.scene->camera_arr[0].focal_len);

	cntl.scene->light = cntl.scene->light->next;
	printf("\nl = xyz(%f, %f, %f)", ((t_light *)(cntl.scene->light->element))->origin.x, ((t_light *)(cntl.scene->light->element))->origin.y, ((t_light *)(cntl.scene->light->element))->origin.z);
	printf("\n    light_color = (%lf, %lf, %lf)", ((t_light *)(cntl.scene->light->element))->light_color.x, ((t_light *)(cntl.scene->light->element))->light_color.y, ((t_light *)(cntl.scene->light->element))->light_color.z);
	printf("\n    bright_ratio = %f", ((t_light *)(cntl.scene->light->element))->bright_ratio);

	printf("\n------------------------------------\n");
	/*
	cntl.win = mlx_new_window(cntl.mlx, cntl.scene->canvas.width, cntl.scene->canvas.height, "Najeong World!");
	image.img = mlx_new_image(cntl.mlx, cntl.scene->canvas.width, cntl.scene->canvas.height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	
	for (int j = cntl.scene->canvas.height-1; j >= 0; --j) {
		for (int i = 0; i < cntl.scene->canvas.width; ++i) {
			double u = (double)(i) / (cntl.scene->canvas.width-1);
			double v = (double)(j) / (cntl.scene->canvas.height-1);
			cntl.scene->ray = ray_primary(&cntl.scene->camera_arr, u, v);
			t_color pixel_color = ray_color(cntl.scene);
			my_mlx_pixel_put(&image, i, cntl.scene->canvas.height - 1 - j, write_color(0, pixel_color));
			// void 포인터에 좌표를 찍는다 image pointer
		}
	}

	mlx_put_image_to_window(cntl.mlx, cntl.win, image.img, 0, 0);
	mlx_key_hook(cntl.win, key_hook, &cntl); // esc key press event
	mlx_hook(cntl.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(cntl.mlx);
	*/
	return (0);
}