/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:18:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:31:45 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

/*
** on & off the camera mode, select camera
*/

void	cntl_camera_off(t_cntl *cntl)
{
	cntl->mode = DEFM;
	printf("DEFAULT MODE\n");
}

void	cntl_camera_on(t_cntl *cntl)
{
	cntl->mode = 2;
	printf("< camera mode >\n[right arrow] key : next camera\n");
	printf("[w,a,s,d] key : move\n[q,e] key : fov\n");
	printf("[mouse click, wheel] : rotate\n");
	printf("[esc] key : DEFAULT MODE\n");
	printf("COORDINATES OF CAMERA.\n%f %f %f\n",
	cntl->scene->cam_onair->origin.x,
	cntl->scene->cam_onair->origin.y,
	cntl->scene->cam_onair->origin.z);
}

void	cntl_select_camera(t_cntl *cntl)
{
	t_objects	*temp;

	temp = (t_objects *)cntl->scene->cam_list;
	while (cntl->scene->cam_onair != (t_camera *)temp->object)
		temp = temp->next;
	if (temp->next == 0)
	{
		cntl->scene->cam_onair = (t_camera *)cntl->scene->cam_list->object;
		printf("COORDINATES OF CAMERA\n%f %f %f\n",
		cntl->scene->cam_onair->origin.x,
		cntl->scene->cam_onair->origin.y, cntl->scene->cam_onair->origin.z);
	}
	else
	{
		cntl->scene->cam_onair = ((t_objects *)temp->next)->object;
		printf("COORDINATES OF CAMERA\n%f %f %f\n",
		cntl->scene->cam_onair->origin.x,
		cntl->scene->cam_onair->origin.y, cntl->scene->cam_onair->origin.z);
	}
}

void	cntl_camera(t_cntl *cntl, int keycode)
{
	if (keycode == KEY_ESC)
		cntl_camera_off(cntl);
	else if (keycode == KEY_AR_R)
		cntl_select_camera(cntl);
	else if (keycode == KEY_Q || keycode == KEY_R)
		cntl_camera_hfov(keycode, cntl);
	else
		cntl_camera_translate(keycode, cntl);
	set_cam(cntl->scene->cam_onair, cntl->scene);
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}
