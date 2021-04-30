/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_camera2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:21:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:32:40 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

/*
** rotate, translate, manage the horizontal field of view(hfov)
*/

void	cntl_cam_rotate(int button, t_cntl *cntl)
{
	t_matrix44	*cam_rotate;
	t_camera	*cam;

	cam = cntl->scene->cam_onair;
	if (button == 1 || button == 7)
		cam_rotate = rotate(vec(0, 5, 0));
	else if (button == 2 || button == 6)
		cam_rotate = rotate(vec(0, -5, 0));
	else if (button == 5)
		cam_rotate = rotate(vec(+5, 0, 0));
	else if (button == 4)
		cam_rotate = rotate(vec(-5, 0, 0));
	else
		return ;
	cam->dir = m_mult_v(cam->dir, 0, cam_rotate);
	free(cam_rotate);
	set_cam(cntl->scene->cam_onair, cntl->scene);
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

void	cntl_camera_translate(int keycode, t_cntl *cntl)
{
	t_camera	*camera;

	camera = cntl->scene->cam_onair;
	if (keycode == KEY_W)
		camera->origin = v_plus(camera->origin, v_multiply(camera->dir, 0.1));
	else if (keycode == KEY_S)
		camera->origin = v_plus(camera->origin, v_multiply(camera->dir, -0.1));
	else if (keycode == KEY_A)
		camera->origin = v_plus(camera->origin,
		v_cross(v_multiply(camera->dir, -0.1), camera->vertical));
	else if (keycode == KEY_D)
		camera->origin = v_plus(camera->origin,
		v_cross(v_multiply(camera->dir, 0.1), camera->vertical));
}

void	cntl_camera_hfov(int keycode, t_cntl *cntl)
{
	t_camera	*camera;

	camera = cntl->scene->cam_onair;
	if (keycode == KEY_Q)
	{
		camera->hfov += 5;
		if (camera->hfov >= 180)
			camera->hfov = 180;
		printf("WIDER FOV\n");
	}
	else if (keycode == KEY_E)
	{
		camera->hfov -= 5;
		if (camera->hfov <= 0)
			camera->hfov = 0;
		printf("NARROWER FOV\n");
	}
}
