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

int		main(int argc, char **argv)
{
	t_cntl	cntl;

	if (argc != 2 && argc != 3)
		return (print_error("Error : Argument Error!\n"));
	cntl.mlx = mlx_init();
	if ((cntl.scene = scene_init()) == NULL)
		return (print_error("Error : scene_init 에러!\n"));
	if (parsing(&cntl, argv[1]) == 0)
		return (print_error("Error : Parsing Error!\n"));
	printf("*** START MINIRT ***\n");
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

int		mlx_put_pixel_to_window(t_cntl *cntl)
{
	int		idx;

	idx = 0;
	cntl->win = mlx_new_window(cntl->mlx, cntl->scene->canv.wid,
	cntl->scene->canv.heig, "NAJEONG's World!");
	if (!(cntl->image = (t_data *)malloc(cntl->scene->c_num *
	sizeof(t_data))))
		print_error("Error : data malloc Fail!!!\n");
	while (idx < cntl->scene->c_num)
	{
		cntl->image[idx].img = mlx_new_image(cntl->mlx,
		cntl->scene->canv.wid, cntl->scene->canv.heig);
		cntl->image[idx].addr = mlx_get_data_addr(cntl->image[idx].img,
		&cntl->image[idx].bits_per_pixel, &cntl->image[idx].line_length,
		&cntl->image[idx].endian);
		idx = mlx_pixel_put_while(cntl, idx);
		idx++;
	}
	return (0);
}

int		mlx_pixel_put_while(t_cntl *cntl, int idx)
{
	int		i;
	int		j;
	t_color	pixel_color;

	j = cntl->scene->canv.heig - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < cntl->scene->canv.wid)
		{
			cntl->scene->ray = ray_primary(&cntl->scene->c_arr[idx],
			(double)i / (cntl->scene->canv.wid - 1), (double)j /
			(cntl->scene->canv.heig - 1));
			pixel_color = ray_color(cntl->scene);
			my_mlx_pixel_put(&cntl->image[idx], i,
			cntl->scene->canv.heig - 1 - j, write_color(0, pixel_color));
			++i;
		}
		--j;
	}
	return (idx);
}

int		mlx_show_window(t_cntl *cntl)
{
	printf("** START SHOW **\n");
	printf("** FINISH SHOW **\n");
	mlx_put_image_to_window(cntl->mlx, cntl->win,
	cntl->image[cntl->scene->camera_idx].img, 0, 0);
	mlx_key_hook(cntl->win, key_hook, cntl);
	mlx_loop(cntl->mlx);
	return (0);
}
