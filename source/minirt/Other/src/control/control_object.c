/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:27:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 06:06:19 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object(int keycode, t_cntl *cntl)
{
	if (cntl->rotate_on == OFF &&
		(keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E
		|| keycode == KEY_A || keycode == KEY_S || keycode == KEY_D))
		cntl_object_translate(keycode, cntl);
	else if (keycode == KEY_R)
		cntl_object_rotate_on_and_off(cntl);
	else if (cntl->rotate_on == ON &&
		(keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E
		|| keycode == KEY_A || keycode == KEY_S || keycode == KEY_D))
		cntl_object_rotate(keycode, cntl);
	else if (keycode == KEY_AR_U || keycode == KEY_AR_D)
		cntl_object_scale(keycode, cntl);
	else if (keycode == KEY_NUM_5 || keycode == KEY_NUM_6
			|| keycode == KEY_NUM_7 || keycode == KEY_NUM_8)
		cntl_object_texture(keycode, cntl);
	else if (keycode == KEY_ESC)
		cntl_object_deselect(cntl);
	render_preview(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

static void	is_hit(t_ray *r, t_cntl *cntl, t_hit_record *rec)
{
	if (hit(r, cntl->scene->objs, rec))
	{
		cntl->selected = rec->obj;
		cntl->mode = OBJM;
		printf("OBJECT SELECTED\nESC key to DEFAULT MODE\n");
	}
	else
	{
		cntl->selected = NULL;
		printf("NO OBJECT THERE\n");
	}
}

void		cntl_object_select(int button, int x, int y, t_cntl *cntl)
{
	double			u;
	double			v;
	t_ray			r;
	t_hit_record	rec;

	if (button != M_CLK_L)
		printf("CLICK LEFT BUTTON!\n");
	else
	{
		rec.t_min = 0.0001;
		rec.t_max = INFINITY;
		u = (double)x / (cntl->scene->canvas.width - 1);
		v = (double)(cntl->scene->canvas.height - y)
		/ (cntl->scene->canvas.height - 1);
		r.origin = cntl->scene->cam_onair->origin;
		r.dir = v_normalize(v_minus(v_plus(
		v_plus(cntl->scene->cam_onair->leftbottom,
		v_multiply(cntl->scene->cam_onair->horizontal, u)),
		v_multiply(cntl->scene->cam_onair->vertical, v)),
		cntl->scene->cam_onair->origin));
		is_hit(&r, cntl, &rec);
	}
	cntl->rotate_on = OFF;
}

void		cntl_object_deselect(t_cntl *cntl)
{
	cntl->mode = DEFM;
	cntl->selected = NULL;
	printf("DEFAULT MODE\n");
}
