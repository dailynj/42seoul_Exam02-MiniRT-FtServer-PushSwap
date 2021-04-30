/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_translate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:41:41 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:39:23 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object_translate(int keycode, t_cntl *cntl)
{
	if (cntl->selected->type == SP)
		translate_sphere(keycode, cntl);
	else if (cntl->selected->type == PL)
		translate_plane(keycode, cntl);
	else if (cntl->selected->type == SQ)
		translate_square(keycode, cntl);
	else if (cntl->selected->type == CY)
		translate_cylinder(keycode, cntl);
	else if (cntl->selected->type == TR)
		translate_triangle(keycode, cntl);
	else if (cntl->selected->type == CO)
		translate_cone(keycode, cntl);
	else if (cntl->selected->type == CU)
		translate_cube(keycode, cntl);
	else if (cntl->selected->type == PY)
		translate_pyramid(keycode, cntl);
}

void		translate_sphere(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W)
		((t_sphere *)(cntl->selected->object))->center.z -= 0.3;
	else if (keycode == KEY_S)
		((t_sphere *)(cntl->selected->object))->center.z += 0.3;
	else if (keycode == KEY_A)
		((t_sphere *)(cntl->selected->object))->center.x -= 0.3;
	else if (keycode == KEY_D)
		((t_sphere *)(cntl->selected->object))->center.x += 0.3;
	else if (keycode == KEY_Q)
		((t_sphere *)(cntl->selected->object))->center.y -= 0.3;
	else if (keycode == KEY_E)
		((t_sphere *)(cntl->selected->object))->center.y += 0.3;
}

void		translate_plane(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W)
		((t_plane *)(cntl->selected->object))->point.z -= 0.3;
	else if (keycode == KEY_S)
		((t_plane *)(cntl->selected->object))->point.z += 0.3;
	else if (keycode == KEY_A)
		((t_plane *)(cntl->selected->object))->point.x -= 0.3;
	else if (keycode == KEY_D)
		((t_plane *)(cntl->selected->object))->point.x += 0.3;
	else if (keycode == KEY_Q)
		((t_plane *)(cntl->selected->object))->point.y -= 0.3;
	else if (keycode == KEY_E)
		((t_plane *)(cntl->selected->object))->point.y += 0.3;
}

void		translate_square(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W)
		((t_square *)(cntl->selected->object))->p.z -= 0.3;
	else if (keycode == KEY_S)
		((t_square *)(cntl->selected->object))->p.z += 0.3;
	else if (keycode == KEY_A)
		((t_square *)(cntl->selected->object))->p.x -= 0.3;
	else if (keycode == KEY_D)
		((t_square *)(cntl->selected->object))->p.x += 0.3;
	else if (keycode == KEY_Q)
		((t_square *)(cntl->selected->object))->p.y -= 0.3;
	else if (keycode == KEY_E)
		((t_square *)(cntl->selected->object))->p.y += 0.3;
}

void		translate_cylinder(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W)
		((t_cylinder *)(cntl->selected->object))->p.z -= 0.3;
	else if (keycode == KEY_S)
		((t_cylinder *)(cntl->selected->object))->p.z += 0.3;
	else if (keycode == KEY_A)
		((t_cylinder *)(cntl->selected->object))->p.x -= 0.3;
	else if (keycode == KEY_D)
		((t_cylinder *)(cntl->selected->object))->p.x += 0.3;
	else if (keycode == KEY_Q)
		((t_cylinder *)(cntl->selected->object))->p.y -= 0.3;
	else if (keycode == KEY_E)
		((t_cylinder *)(cntl->selected->object))->p.y += 0.3;
}
