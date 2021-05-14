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

// esc key press event
int	key_hook(int keycode, t_cntl *cntl)
{
	(void) keycode;
	(void) cntl;
	// if (keycode == 53)
	// {
	// 	mlx_destroy_window(cntl->mlx, cntl->win);
	// 	exit(0);
	// }
	return (0);
}

// close button press event
int	exit_hook()
{
	exit(0);
}
