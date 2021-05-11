/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_scale2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:38:18 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:38:40 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		scale_cone(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
		((t_cone *)cntl->selected->object)->height += 0.25;
	else if (keycode == KEY_AR_D)
		((t_cone *)cntl->selected->object)->height -= 0.25;
}

void		scale_cube(int keycode, t_cntl *cntl)
{
	double	scale;
	t_cube	*temp;

	scale = (keycode == KEY_AR_U) ? 0.25 : -0.25;
	printf("%f\n", ((t_cube *)cntl->selected->object)->len);
	temp = cube(((t_cube *)cntl->selected->object)->p,
				((t_cube *)cntl->selected->object)->len + scale);
	free(cntl->selected->object);
	cntl->selected->object = temp;
}

void		scale_pyramid(int keycode, t_cntl *cntl)
{
	double		scale;
	t_pyramid	*temp;

	scale = (keycode == KEY_AR_U) ? 0.25 : -0.25;
	temp = pyramid(((t_pyramid *)cntl->selected->object)->p,
		((t_pyramid *)cntl->selected->object)->len + scale);
	free(cntl->selected->object);
	cntl->selected->object = temp;
}
