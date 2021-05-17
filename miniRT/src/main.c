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
	t_cntl	cntl;

	if (argc != 2 && argc != 3)
		return (print_error("Error : Argument Error!\n"));
	cntl.mlx = mlx_init();
	if ((cntl.scene = scene_init()) == NULL)
		return (print_error("Error : scene_init 에러!\n"));
	if (parsing(&cntl, argv[1]) == 0)
		return (print_error("Error : Parsing Error!\n"));
	mlx_put_pixel_to_window(&cntl);
	if (argc == 2)
		return (mlx_show_window(&cntl));
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) != 0)
			return (print_error("Error : --save 인수가 잘못되었습니다\n"));
		return (mlx_save_image(&cntl));
	}
	return (0);
}

int mlx_put_pixel_to_window(t_cntl *cntl)
{
	t_color	pixel_color;
	int			i;
	int			j;
	int			idx;
	
    cntl->win = mlx_new_window(cntl->mlx, cntl->scene->canvas.width, cntl->scene->canvas.height, "NAJEONG's World!");
	if (!(cntl->image = (t_data *)malloc(cntl->scene->camera_num * sizeof(t_data))))
		print_error("Error : data malloc Fail!!!\n");
	idx = 0;
	while (idx < cntl->scene->camera_num){
		cntl->image[idx].img = mlx_new_image(cntl->mlx, cntl->scene->canvas.width, cntl->scene->canvas.height);
		cntl->image[idx].addr = mlx_get_data_addr(cntl->image[idx].img, &cntl->image[idx].bits_per_pixel, &cntl->image[idx].line_length, &cntl->image[idx].endian);
		j = cntl->scene->canvas.height - 1;
		while (j >= 0)
		{
			i = 0;
			while (i < cntl->scene->canvas.width)
			{
				cntl->scene->ray = ray_primary(&cntl->scene->camera_arr[idx], (double)i / (cntl->scene->canvas.width - 1), (double)j / (cntl->scene->canvas.height - 1));
				pixel_color = ray_color(cntl->scene);
				my_mlx_pixel_put(&cntl->image[idx], i, cntl->scene->canvas.height - 1 - j, write_color(0, pixel_color));
				++i;
			}
			--j;
		}
		idx++;
	}
	return (0);
}

int	mlx_show_window(t_cntl *cntl)
{
	printf("** START SHOW **\n");
	printf("** FINISH SHOW **\n");
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->image[cntl->scene->camera_idx].img, 0, 0);
	mlx_key_hook(cntl->win, key_hook, cntl);
	mlx_loop(cntl->mlx);
	return (0);
}

t_bmp	bmp_set_header(t_scene *scene)
{
	t_bmp	bmp;

	bmp.file_h.sign1 = 'B';
	bmp.file_h.sign2 = 'M';
	bmp.file_h.file_size = 14 + 40 +
			(int)(scene->canvas.width) * (int)(scene->canvas.height) * 4;
	bmp.file_h.reserved1 = 0;
	bmp.file_h.reserved2 = 0;
	bmp.file_h.start_bmp = 14 + 40;
	bmp.info_h.size = 40;
	bmp.info_h.witdh = (int)(scene->canvas.width);
	bmp.info_h.height = -(int)(scene->canvas.height);
	bmp.info_h.planes = 1;
	bmp.info_h.bitcount = 32;
	bmp.info_h.compression = 0;
	bmp.info_h.sizeimage = 4 * (int)(scene->canvas.width) * (int)(scene->canvas.height);
	bmp.info_h.x_pelspermeter = (int)(scene->canvas.width);
	bmp.info_h.y_pelspermeter = (int)(scene->canvas.height);
	bmp.info_h.color_used = 0xffffff;
	bmp.info_h.color_important = 0;
	return (bmp);
}

int	mlx_save_image(t_cntl *cntl)
{
	int			i;
	int			fd;
	t_bmp		bmp;
	
	printf("** START SAVE **\n");
	fd = open("miniRT.bmp", O_CREAT | O_WRONLY | O_TRUNC);
	bmp = bmp_set_header(cntl->scene);
	write(fd, &bmp, 54);
	i = 0;
	while (i < (cntl->image[0].line_length / 4) * (int)(cntl->scene->canvas.height))
	{
		if (i % (cntl->image[0].line_length / 4) < (int)(cntl->scene->canvas.width))
			write(fd, &cntl->image[0].addr[i * 4], 4);
		++i;
	}
	close(fd);
	printf("** FINISH SAVE **\n");
	return (0);
}