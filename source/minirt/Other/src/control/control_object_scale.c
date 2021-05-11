/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_scale.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:11:44 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:38:34 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object_scale(int keycode, t_cntl *cntl)
{
	if (cntl->selected->type == SP)
		scale_sphere(keycode, cntl);
	else if (cntl->selected->type == SQ)
		scale_square(keycode, cntl);
	else if (cntl->selected->type == CY)
		scale_cylinder(keycode, cntl);
	else if (cntl->selected->type == CO)
		scale_cone(keycode, cntl);
	else if (cntl->selected->type == CU)
		scale_cube(keycode, cntl);
	else if (cntl->selected->type == PY)
		scale_pyramid(keycode, cntl);
}

void		scale_sphere(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
		((t_sphere *)cntl->selected->object)->radius += 0.25;
	else if (keycode == KEY_AR_D)
		((t_sphere *)cntl->selected->object)->radius -= 0.25;
}

void		scale_square(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
		((t_square *)cntl->selected->object)->side_len += 0.25;
	else if (keycode == KEY_AR_D)
		((t_square *)cntl->selected->object)->side_len -= 0.25;
}

void		scale_cylinder(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
	{
		((t_cylinder *)cntl->selected->object)->radius += 0.25;
		((t_cylinder *)cntl->selected->object)->len += 0.25;
	}
	else if (keycode == KEY_AR_D)
	{
		((t_cylinder *)cntl->selected->object)->radius -= 0.25;
		((t_cylinder *)cntl->selected->object)->len -= 0.25;
	}
}
