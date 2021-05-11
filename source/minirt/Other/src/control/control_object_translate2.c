/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_translate2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:42:08 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:40:31 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		translate_cube_x(int keycode, t_cntl *cntl)
{
	int	i;

	i = -1;
	if (keycode == KEY_D)
	{
		while (++i < 6)
			((t_cube *)(cntl->selected->object))->sq[i]->p.x += 0.3;
		((t_cube *)(cntl->selected->object))->p.x += 0.3;
	}
	else if (keycode == KEY_A)
	{
		while (++i < 6)
			((t_cube *)(cntl->selected->object))->sq[i]->p.x -= 0.3;
		((t_cube *)(cntl->selected->object))->p.x -= 0.3;
	}
}

void		translate_cube_y(int keycode, t_cntl *cntl)
{
	int		i;

	i = -1;
	if (keycode == KEY_Q)
	{
		while (++i < 6)
			((t_cube *)(cntl->selected->object))->sq[i]->p.y -= 0.3;
		((t_cube *)(cntl->selected->object))->p.y -= 0.3;
	}
	else if (keycode == KEY_E)
	{
		while (++i < 6)
			((t_cube *)(cntl->selected->object))->sq[i]->p.y += 0.3;
		((t_cube *)(cntl->selected->object))->p.y += 0.3;
	}
}

void		translate_cube_z(int keycode, t_cntl *cntl)
{
	int	i;

	i = -1;
	if (keycode == KEY_S)
	{
		while (++i < 6)
			((t_cube *)(cntl->selected->object))->sq[i]->p.z += 0.3;
		((t_cube *)(cntl->selected->object))->p.z -= 0.3;
	}
	else if (keycode == KEY_W)
	{
		while (++i < 6)
			((t_cube *)(cntl->selected->object))->sq[i]->p.z -= 0.3;
		((t_cube *)(cntl->selected->object))->p.z -= 0.3;
	}
}

void		translate_cube(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W || keycode == KEY_S)
		translate_cube_z(keycode, cntl);
	else if (keycode == KEY_Q || keycode == KEY_E)
		translate_cube_y(keycode, cntl);
	else if (keycode == KEY_A || keycode == KEY_D)
		translate_cube_x(keycode, cntl);
}

void		translate_cone(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W)
		((t_cone *)(cntl->selected->object))->p.z -= 0.3;
	else if (keycode == KEY_S)
		((t_cone *)(cntl->selected->object))->p.z += 0.3;
	else if (keycode == KEY_A)
		((t_cone *)(cntl->selected->object))->p.x -= 0.3;
	else if (keycode == KEY_D)
		((t_cone *)(cntl->selected->object))->p.x += 0.3;
	else if (keycode == KEY_Q)
		((t_cone *)(cntl->selected->object))->p.y -= 0.3;
	else if (keycode == KEY_E)
		((t_cone *)(cntl->selected->object))->p.y += 0.3;
}
