/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_translate3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:44:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:07:09 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		pyramid_z_move_neg(t_cntl *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			((t_pyramid *)(c->selected->object))->tr[i]->p[j].z -= 0.3;
	}
	((t_pyramid *)(c->selected->object))->sq->p.z -= 0.3;
	((t_pyramid *)(c->selected->object))->p.z -= 0.3;
}

void		pyramid_z_move_pos(t_cntl *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			((t_pyramid *)(c->selected->object))->tr[i]->p[j].z += 0.3;
	}
	((t_pyramid *)(c->selected->object))->sq->p.z += 0.3;
	((t_pyramid *)(c->selected->object))->p.z += 0.3;
}

void		pyramid_x_move_neg(t_cntl *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			((t_pyramid *)(c->selected->object))->tr[i]->p[j].x -= 0.3;
	}
	((t_pyramid *)(c->selected->object))->sq->p.x -= 0.3;
	((t_pyramid *)(c->selected->object))->p.x -= 0.3;
}

void		pyramid_x_move_pos(t_cntl *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			((t_pyramid *)(c->selected->object))->tr[i]->p[j].x += 0.3;
	}
	((t_pyramid *)(c->selected->object))->sq->p.x += 0.3;
	((t_pyramid *)(c->selected->object))->p.x += 0.3;
}
