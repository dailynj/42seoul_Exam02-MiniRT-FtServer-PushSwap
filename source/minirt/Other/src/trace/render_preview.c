/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_preview.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:21:14 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:57:13 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"
#include "mlx.h"
#include "utils.h"
#include "control.h"
#include <pthread.h>

static void		pixel_put_preview(t_scene *s, t_ray *r, int *i, int light_on)
{
	double			uv[2];
	t_color			pixel_color;

	pixel_color = color(0, 0, 0);
	uv[0] = (double)i[0] / (s->canvas.height - 1);
	uv[1] = (double)i[1] / (s->canvas.width - 1);
	r->origin = s->cam_onair->origin;
	r->dir = v_normalize(v_minus(v_plus(v_plus(s->cam_onair->leftbottom,
				v_multiply(s->cam_onair->horizontal, uv[1])),
				v_multiply(s->cam_onair->vertical, uv[0])),
										s->cam_onair->origin));
	pixel_color = v_plus(pixel_color, ray_color_preview(r, s, light_on));
	pixel_color = v_plus(pixel_color, s->global.ambient);
	filter(&pixel_color, &s->global);
	my_mlx_pixel_put(s->img, i[1], s->canvas.height - i[0] - 1,
									color_to_int(pixel_color));
}

static void		*render_preview_thread(void *thread_data)
{
	t_pth_data		t;
	t_scene			*s;
	int				i[2];
	t_ray			r;

	t = *(t_pth_data *)thread_data;
	s = t.c->scene;
	i[0] = s->canvas.height - 1 - t.lane;
	while (i[0] >= 0)
	{
		i[1] = -1;
		while (++i[1] < s->canvas.width)
			pixel_put_preview(s, &r, i, t.c->light_on);
		i[0] -= t.count;
	}
	return (NULL);
}

void			render_preview(t_cntl *cntl)
{
	pthread_t		p_thread[COUNT];
	t_pth_data		data[COUNT];
	int				i;

	i = -1;
	while (++i < COUNT)
	{
		data[i].count = COUNT;
		data[i].c = cntl;
	}
	i = -1;
	while (++i < COUNT)
	{
		data[i].lane = i;
		if (pthread_create(&p_thread[i], NULL, render_preview_thread,
											(void *)&data[i]) < 0)
		{
			perror("thread create error : ");
			exit(0);
		}
	}
	i = -1;
	while (++i < COUNT)
		pthread_join(p_thread[i], NULL);
}
