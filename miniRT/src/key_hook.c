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
		mlx_destroy_window(cntl->mlx, cntl->win);
		exit(0);
	}
	else if (keycode == KEY_RIGHT){
		
	}
	return (0);
}

// close button press event
int	exit_hook()
{
	exit(0);
}
