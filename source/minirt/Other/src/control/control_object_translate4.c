/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_translate4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:07:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:08:03 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		pyramid_y_move_neg(t_cntl *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			((t_pyramid *)(c->selected->object))->tr[i]->p[j].y -= 0.3;
	}
	((t_pyramid *)(c->selected->object))->sq->p.y -= 0.3;
	((t_pyramid *)(c->selected->object))->p.y -= 0.3;
}

void		pyramid_y_move_pos(t_cntl *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			((t_pyramid *)(c->selected->object))->tr[i]->p[j].y += 0.3;
	}
	((t_pyramid *)(c->selected->object))->sq->p.y += 0.3;
	((t_pyramid *)(c->selected->object))->p.y += 0.3;
}

void		translate_pyramid(int keycode, t_cntl *c)
{
	if (keycode == KEY_W)
		pyramid_z_move_neg(c);
	else if (keycode == KEY_S)
		pyramid_z_move_pos(c);
	else if (keycode == KEY_A)
		pyramid_x_move_neg(c);
	else if (keycode == KEY_D)
		pyramid_x_move_pos(c);
	else if (keycode == KEY_Q)
		pyramid_y_move_neg(c);
	else if (keycode == KEY_E)
		pyramid_y_move_pos(c);
}

void		translate_triangle(int keycode, t_cntl *c)
{
	int	i;

	i = -1;
	if (keycode == KEY_W)
		while (++i < 3)
			((t_triangle *)(c->selected->object))->p[i].z -= 0.3;
	else if (keycode == KEY_S)
		while (++i < 3)
			((t_triangle *)(c->selected->object))->p[i].z += 0.3;
	else if (keycode == KEY_A)
		while (++i < 3)
			((t_triangle *)(c->selected->object))->p[i].x -= 0.3;
	else if (keycode == KEY_D)
		while (++i < 3)
			((t_triangle *)(c->selected->object))->p[i].x += 0.3;
	else if (keycode == KEY_Q)
		while (++i < 3)
			((t_triangle *)(c->selected->object))->p[i].y -= 0.3;
	else if (keycode == KEY_E)
		while (++i < 3)
			((t_triangle *)(c->selected->object))->p[i].y += 0.3;
}
