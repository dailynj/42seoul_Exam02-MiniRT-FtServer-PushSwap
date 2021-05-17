/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:51:47 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:45:37 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_square	*square(t_point point, t_vec normal, double length)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	sq->point = point;
	sq->normal = normal;
	sq->length = length;
	return (sq);
}

t_bool		hit_square(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	t_vec		u;
	t_vec		v;
	double		u_len;
	double		v_len;

	sq = world->element;
	if (hit_plane(world, ray, rec) == FALSE)
		return (FALSE);
	u = vec(0, 1, 0);
	if ((sq->normal.x == 0 && sq->normal.y == 1) && sq->normal.z == 0)
		u = vec(0, 0, 1);
	v = v_cr(sq->normal, u);
	u_len = vec_dot(u, v_minus(rec->p, sq->point)) / vec_dot(u, u);
	v_len = vec_dot(v, v_minus(rec->p, sq->point)) / vec_dot(v, v);
	if ((u_len < sq->length / -2.0) || (u_len > sq->length / 2.0) ||
		(v_len < sq->length / -2.0) || (v_len > sq->length / 2.0))
		return (FALSE);
	set_face_normal(ray, rec);
	return (TRUE);
}
