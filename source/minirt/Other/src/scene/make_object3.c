/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:20:40 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:21:02 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_texture	*texture(int texture_type, t_color albedo)
{
	t_texture	*texture;

	if (!(texture = (t_texture *)malloc(sizeof(t_texture))))
		malloc_error();
	texture->type = texture_type;
	texture->albedo = albedo;
	texture->density = 0;
	return (texture);
}

t_texture	*texture_img(t_data *img)
{
	t_texture *texture;

	if (!(texture = (t_texture *)malloc(sizeof(t_texture))))
		malloc_error();
	texture->type = IMAGE;
	texture->albedo = color(0, 0, 0);
	texture->img = img;
	return (texture);
}
