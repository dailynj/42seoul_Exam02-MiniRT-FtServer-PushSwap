/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:02:34 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:34:12 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_init(t_cntl *cntl, char *filepath)
{
	t_data		*img;

	cntl->mlx = mlx_init();
	cntl->scene = read_rt(filepath, cntl->mlx);
	cntl->selected = NULL;
	cntl->mode = DEFM;
	cntl->light_on = OFF;
	cntl->rotate_on = OFF;
	cntl->texture_on = OFF;
	cntl_display_resolution(cntl);
	cntl->win = mlx_new_window(cntl->mlx, cntl->scene->canvas.width,
	cntl->scene->canvas.height, "HYEONKIM MINIRT");
	if (!(img = (t_data *)malloc(sizeof(t_data))))
		exit(0);
	img->img = mlx_new_image(cntl->mlx, cntl->scene->canvas.width,
										cntl->scene->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
									&img->line_length, &img->endian);
	cntl->img = img;
	cntl->scene->img = img;
	cntl->scene->cam_onair = cntl->scene->cam_list->object;
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

void		cntl_init_except_resolution(t_cntl *cntl, char *filepath)
{
	t_data		*img;

	cntl->mlx = mlx_init();
	cntl->scene = read_rt(filepath, cntl->mlx);
	cntl->selected = NULL;
	cntl->mode = DEFM;
	cntl->light_on = OFF;
	cntl->rotate_on = OFF;
	cntl->texture_on = OFF;
	cntl->win = mlx_new_window(cntl->mlx, cntl->scene->canvas.width,
				cntl->scene->canvas.height, "HYEONKIM MINIRT");
	if (!(img = (t_data *)malloc(sizeof(t_data))))
		malloc_error();
	img->img = mlx_new_image(cntl->mlx,
				cntl->scene->canvas.width, cntl->scene->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian);
	cntl->img = img;
	cntl->scene->img = img;
	cntl->scene->cam_onair = cntl->scene->cam_list->object;
	set_cam(cntl->scene->cam_onair, cntl->scene);
}
