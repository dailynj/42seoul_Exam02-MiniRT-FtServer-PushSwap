/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:47:35 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:16:57 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_display_resolution(t_cntl *cntl)
{
	int		x;
	int		y;

	mlx_get_screen_size(cntl->mlx, &x, &y);
	if (cntl->scene->canvas.width > x)
		cntl->scene->canvas.width = x;
	if (cntl->scene->canvas.height > y)
		cntl->scene->canvas.height = y;
}

int			cntl_key_press(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_O)
		cntl_light_on_and_off(cntl);
	if (cntl->mode == DEFM &&
		(keycode == KEY_NUM_9 || keycode == KEY_NUM_1 ||
		keycode == KEY_NUM_2 || keycode == KEY_NUM_3 || keycode == KEY_NUM_4))
		cntl_filter_change(keycode, cntl);
	if (keycode == KEY_SP)
		rendor_mode(cntl);
	else if (keycode == KEY_C && cntl->mode == DEFM)
		cntl_camera_on(cntl);
	if (keycode == 53 && cntl->mode == DEFM)
		cntl_close();
	else if (cntl->mode == CAMM)
		cntl_camera(cntl, keycode);
	else if (cntl->mode == OBJM)
		cntl_object(keycode, cntl);
	else if (keycode == KEY_L && cntl->mode != LIGM)
		cntl_light_mode_on(cntl);
	else if (cntl->mode == LIGM)
		cntl_light(cntl, keycode);
	return (1);
}

void		rendor_mode(t_cntl *cntl)
{
	int		samples_per_pixel;
	char	*line;

	printf("WRITE SAMPLES PER PIXEL\n");
	get_next_line(0, &line);
	samples_per_pixel = ft_atoi(line);
	free(line);
	cntl->scene->global.samples_per_pixel = samples_per_pixel;
	render(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

int			cntl_mouse_click(int button, int x, int y, t_cntl *cntl)
{
	if (cntl->mode == DEFM)
		cntl_object_select(button, x, y, cntl);
	if (cntl->mode == CAMM)
		cntl_cam_rotate(button, cntl);
	return (0);
}

void		my_mlx_control(t_cntl *cntl)
{
	mlx_hook(cntl->win, 2, (1L << 0), cntl_key_press, cntl);
	mlx_hook(cntl->win, 17, (1L << 5), cntl_click_x, cntl);
	mlx_hook(cntl->win, 4, (1L << 6), cntl_mouse_click, cntl);
	mlx_loop(cntl->mlx);
}
