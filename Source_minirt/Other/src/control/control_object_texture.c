/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:22:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 06:09:26 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object_texture(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_NUM_5)
	{
		cntl->selected->texture->type = CHECK;
		printf("TEXTURE : CHECKERBOARD\n");
	}
	else if (keycode == KEY_NUM_6)
	{
		cntl->selected->texture->type = RAINBOW;
		printf("TEXTURE : RAINBOW\n");
	}
	else if (keycode == KEY_NUM_7)
	{
		cntl->selected->texture->type = WAVE;
		printf("TEXTURE : WAVE\n");
	}
	else if (keycode == KEY_NUM_8)
	{
		cntl->selected->texture->type = DEFAULT;
		printf("TEXTURE : DEFAULT\n");
	}
}
