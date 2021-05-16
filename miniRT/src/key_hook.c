/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:12 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 00:43:12 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "mlx.h"

int	key_hook(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cntl->mlx, cntl->win);
		exit(0);
	}
	else if (keycode == KEY_RIGHT)
	{
		if (cntl->scene->camera_idx == cntl->scene->camera_num - 1)
			cntl->scene->camera_idx = 0;
		else
			cntl->scene->camera_idx = cntl->scene->camera_idx + 1;
		mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->image
				[cntl->scene->camera_idx].img, 0, 0);
	}
	else if (keycode == KEY_LEFT)
	{
		if (cntl->scene->camera_idx == 0)
			cntl->scene->camera_idx = cntl->scene->camera_num - 1;
		else
			cntl->scene->camera_idx = cntl->scene->camera_idx - 1;
		mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->image
				[cntl->scene->camera_idx].img, 0, 0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
