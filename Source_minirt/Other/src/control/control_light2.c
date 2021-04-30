/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_light2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:31:32 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:35:46 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

/*
** manage brightness, translate
*/

void	cntl_light_bright_up(t_cntl *cntl)
{
	double		brightness;
	t_color		*light_color;

	brightness = ((t_spot_light *)(cntl->selected->object))->brightness;
	light_color = &((t_spot_light *)(cntl->selected->object))->color;
	if (cntl->selected->type == SPOT_LIGHT)
	{
		((t_spot_light *)(cntl->selected->object))->brightness += 0.1;
		if (((t_spot_light *)(cntl->selected->object))->brightness > 1)
			((t_spot_light *)(cntl->selected->object))->brightness = 1;
		*light_color = v_multiply(*light_color, 1.0 / brightness);
		brightness = ((t_spot_light *)(cntl->selected->object))->brightness;
		*light_color = v_multiply(*light_color, brightness);
	}
	printf("BRIGHTER\n");
}

void	cntl_light_bright_down(t_cntl *cntl)
{
	double		brightness;
	t_color		*light_color;

	brightness = ((t_spot_light *)(cntl->selected->object))->brightness;
	light_color = &((t_spot_light *)(cntl->selected->object))->color;
	if (cntl->selected->type == SPOT_LIGHT)
	{
		((t_spot_light *)(cntl->selected->object))->brightness -= 0.1;
		if (((t_spot_light *)(cntl->selected->object))->brightness <= 0)
			((t_spot_light *)(cntl->selected->object))->brightness = 0.000001;
		*light_color = v_multiply(*light_color, 1.0 / brightness);
		brightness = ((t_spot_light *)(cntl->selected->object))->brightness;
		*light_color = v_multiply(*light_color, brightness);
	}
	printf("DARKER\n");
}

void	cntl_light_translate(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W)
		((t_spot_light *)(cntl->selected->object))->p.z -= 0.3;
	else if (keycode == KEY_S)
		((t_spot_light *)(cntl->selected->object))->p.z += 0.3;
	else if (keycode == KEY_A)
		((t_spot_light *)(cntl->selected->object))->p.x -= 0.3;
	else if (keycode == KEY_D)
		((t_spot_light *)(cntl->selected->object))->p.x += 0.3;
	else if (keycode == KEY_Q)
		((t_spot_light *)(cntl->selected->object))->p.y -= 0.3;
	else if (keycode == KEY_E)
		((t_spot_light *)(cntl->selected->object))->p.y += 0.3;
	printf("COORDINATES OF LIGHT\n%f %f %f\n",
		((t_spot_light *)(cntl->selected->object))->p.x
		, ((t_spot_light *)(cntl->selected->object))->p.y
		, ((t_spot_light *)(cntl->selected->object))->p.z);
}
