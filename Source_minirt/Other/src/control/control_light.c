/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:35:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	cntl_light_mode_on(t_cntl *cntl)
{
	cntl->mode = LIGM;
	if (cntl->selected == 0)
	{
		while (cntl->scene->objs->type != SPOT_LIGHT)
			cntl->scene->objs = cntl->scene->objs->next;
		cntl->selected = cntl->scene->objs;
	}
	printf("< light mode >\n[right arrow] key : next light\n");
}

void	cntl_light_on_and_off(t_cntl *cntl)
{
	if (cntl->light_on == OFF)
	{
		cntl->light_on = ON;
		printf("light on(if you press spacebar, light off)\n");
	}
	else
	{
		cntl->light_on = OFF;
		printf("light off(if you press spacebar, light on)\n");
	}
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

void	cntl_light_select(t_cntl *cntl)
{
	t_objects	*temp;

	if (cntl->selected == 0 || cntl->selected->next == 0)
		temp = (t_objects *)cntl->scene->objs;
	else
		temp = (t_objects *)cntl->selected->next;
	while (temp && temp->type != SPOT_LIGHT)
		temp = temp->next;
	if (temp == 0)
	{
		temp = (t_objects *)cntl->scene->objs;
		while (temp && temp->type != SPOT_LIGHT)
			temp = temp->next;
		cntl->selected = temp;
	}
	else
		cntl->selected = temp;
	printf("COORDINATES OF LIGHT\n%f %f %f\n",
		((t_spot_light *)(cntl->selected->object))->p.x
		, ((t_spot_light *)(cntl->selected->object))->p.y
		, ((t_spot_light *)(cntl->selected->object))->p.z);
}

void	cntl_light_mode_off(t_cntl *cntl)
{
	printf("light deselect\n");
	cntl->selected = NULL;
	cntl->mode = DEFM;
}

void	cntl_light(t_cntl *cntl, int keycode)
{
	if (keycode == KEY_AR_R)
		cntl_light_select(cntl);
	else if (keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E
		|| keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		cntl_light_translate(keycode, cntl);
	else if (keycode == KEY_ESC)
		cntl_light_mode_off(cntl);
	else if (keycode == KEY_AR_U)
		cntl_light_bright_up(cntl);
	else if (keycode == KEY_AR_D)
		cntl_light_bright_down(cntl);
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}
