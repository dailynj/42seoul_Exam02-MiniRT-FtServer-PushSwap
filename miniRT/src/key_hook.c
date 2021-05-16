/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:50:12 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:44:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "mlx.h"

// esc key press event
int	key_hook(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_ESC)
	{
		printf("esc\n");
		mlx_destroy_window(cntl->mlx, cntl->win);
		exit(0);
	}
	else if (keycode == KEY_RIGHT){
		printf("right\n");
		cntl->scene->camera_idx++;
		if (cntl->scene->camera_idx == cntl->scene->camera_num)
			cntl->scene->camera_idx = 0;
		mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->image[cntl->scene->camera_idx].img, 0, 0);
		mlx_key_hook(cntl->win, key_hook, &cntl);
		mlx_loop(cntl->mlx);
	}
	else if (keycode == KEY_LEFT){
		printf("left\n");
		cntl->scene->camera_idx--;
		if (cntl->scene->camera_idx == -1)
			cntl->scene->camera_idx = cntl->scene->camera_idx - 1;
		mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->image[cntl->scene->camera_idx].img, 0, 0);
		mlx_key_hook(cntl->win, key_hook, &cntl);
		mlx_loop(cntl->mlx);
	}
	return (0);
}

// close button press event
int	exit_hook()
{
	exit(0);
}
