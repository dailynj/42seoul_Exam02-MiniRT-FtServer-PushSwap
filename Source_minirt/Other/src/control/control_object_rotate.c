/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:30:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:37:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object_rotate_on_and_off(t_cntl *cntl)
{
	if (cntl->rotate_on == OFF)
	{
		cntl->rotate_on = ON;
		printf("OBJECT ROTATE MODE ON\n");
	}
	else if (cntl->rotate_on == ON)
	{
		cntl->rotate_on = OFF;
		printf("OBJECT ROTATE MODE OFF\n");
	}
}

void		cntl_object_rotate_sq_cu_py(t_cntl *cntl, int keycode)
{
	t_vec		r_deg;

	if (cntl->selected->type == SP || cntl->selected->type == TR)
		return ;
	r_deg = (cntl->selected->rotate == NULL) ? vec(0, 0, 0) :
			cntl->selected->rotate->rotate_deg;
	if (keycode == KEY_Q)
		r_deg = v_plus(r_deg, vec(15, 0, 0));
	else if (keycode == KEY_A)
		r_deg = v_plus(r_deg, vec(-15, 0, 0));
	else if (keycode == KEY_W)
		r_deg = v_plus(r_deg, vec(0, 15, 0));
	else if (keycode == KEY_S)
		r_deg = v_plus(r_deg, vec(0, -15, 0));
	else if (keycode == KEY_E)
		r_deg = v_plus(r_deg, vec(0, 0, 15));
	else if (keycode == KEY_D)
		r_deg = v_plus(r_deg, vec(0, 0, -15));
	if (cntl->selected->rotate != NULL)
	{
		free(cntl->selected->rotate);
		free(cntl->selected->rotate_normal);
	}
	cntl->selected->rotate = rotate(r_deg);
	cntl->selected->rotate_normal = rotate_normal(cntl->selected->rotate);
}

void		cntl_object_rotate(int keycode, t_cntl *cntl)
{
	if (cntl->selected->type == CY)
		rotate_cylinder(keycode, cntl);
	else if (cntl->selected->type == CO)
		rotate_cone(keycode, cntl);
	else if (cntl->selected->type == SQ ||
	cntl->selected->type == CU || cntl->selected->type == PY)
		cntl_object_rotate_sq_cu_py(cntl, keycode);
}

void		rotate_cylinder(int keycode, t_cntl *cntl)
{
	t_matrix44	*axis_rotate;

	if (keycode == KEY_A)
		axis_rotate = rotate(vec(0, +10, 0));
	else if (keycode == KEY_D)
		axis_rotate = rotate(vec(0, -10, 0));
	else if (keycode == KEY_W)
		axis_rotate = rotate(vec(+10, 0, 0));
	else if (keycode == KEY_S)
		axis_rotate = rotate(vec(-10, 0, 0));
	else if (keycode == KEY_Q)
		axis_rotate = rotate(vec(0, 0, -10));
	else if (keycode == KEY_E)
		axis_rotate = rotate(vec(0, 0, +10));
	else
		return ;
	((t_cylinder *)cntl->selected->object)->vec =
	m_mult_v(((t_cylinder *)cntl->selected->object)->vec, 0, axis_rotate);
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

void		rotate_cone(int keycode, t_cntl *cntl)
{
	t_matrix44	*axis_rotate;

	if (keycode == KEY_D)
		axis_rotate = rotate(vec(0, +10, 0));
	else if (keycode == KEY_A)
		axis_rotate = rotate(vec(0, -10, 0));
	else if (keycode == KEY_W)
		axis_rotate = rotate(vec(+10, 0, 0));
	else if (keycode == KEY_S)
		axis_rotate = rotate(vec(-10, 0, 0));
	else if (keycode == KEY_Q)
		axis_rotate = rotate(vec(0, 0, -10));
	else if (keycode == KEY_E)
		axis_rotate = rotate(vec(0, 0, +10));
	else
		return ;
	((t_cone *)cntl->selected->object)->axis =
	m_mult_v(((t_cone *)cntl->selected->object)->axis, 0, axis_rotate);
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}
