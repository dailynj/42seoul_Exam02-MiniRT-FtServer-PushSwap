/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:34:03 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 19:54:44 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

/*
** Sepia algorithm
** outputRed = (inputRed * .393) + (inputGreen *.769) + (inputBlue * .189)
** outputGreen = (inputRed * .349) + (inputGreen *.686) + (inputBlue * .168)
** outputBlue = (inputRed * .272) + (inputGreen *.534) + (inputBlue * .131)
*/

static void		filter_sepia(t_color *pixel_color)
{
	t_color temp;

	temp = *pixel_color;
	pixel_color->x = temp.x * 0.393 + temp.y * 0.769 + temp.z * 0.189;
	pixel_color->y = temp.x * 0.349 + temp.y * 0.686 + temp.z * 0.168;
	pixel_color->z = temp.x * 0.272 + temp.y * 0.534 + temp.z * 0.131;
}

static void		filter_red(t_color *pixel_color)
{
	pixel_color->y = 0.0;
	pixel_color->z = 0.0;
}

static void		filter_green(t_color *pixel_color)
{
	pixel_color->x = 0.0;
	pixel_color->z = 0.0;
}

static void		filter_blue(t_color *pixel_color)
{
	pixel_color->x = 0.0;
	pixel_color->y = 0.0;
}

void			filter(t_color *pixel_color, t_global *global)
{
	if (global->filter_type == SEPHIA)
		filter_sepia(pixel_color);
	else if (global->filter_type == RED)
		filter_red(pixel_color);
	else if (global->filter_type == GREEN)
		filter_green(pixel_color);
	else if (global->filter_type == BLUE)
		filter_blue(pixel_color);
	else if (global->filter_type == DEFAULT)
		*pixel_color = v_min(*pixel_color, vec(1.0, 1.0, 1.0));
	*pixel_color = v_min(*pixel_color, vec(1.0, 1.0, 1.0));
}
