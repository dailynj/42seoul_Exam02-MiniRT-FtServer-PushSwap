/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:40:33 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:32:59 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	cntl_filter_change(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_NUM_9)
		cntl->scene->global.filter_type = DEFAULT;
	if (keycode == KEY_NUM_1)
		cntl->scene->global.filter_type = SEPHIA;
	if (keycode == KEY_NUM_2)
		cntl->scene->global.filter_type = RED;
	if (keycode == KEY_NUM_3)
		cntl->scene->global.filter_type = GREEN;
	if (keycode == KEY_NUM_4)
		cntl->scene->global.filter_type = BLUE;
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}
