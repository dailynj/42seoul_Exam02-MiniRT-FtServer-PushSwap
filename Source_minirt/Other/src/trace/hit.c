/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:52:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int			hit_objects(t_ray *r, t_objects *object, t_hit_record *rec)
{
	int		hit_result;

	hit_result = FALSE;
	if (object->type == SP)
		hit_result = hit_sphere(r, object, rec);
	else if (object->type == TR)
		hit_result = hit_triangle(r, object, rec);
	else if (object->type == CY)
		hit_result = hit_cylinder(r, object, rec);
	else if (object->type == SQ)
		hit_result = check_rotate_square(r, object, rec);
	else if (object->type == PL)
		hit_result = hit_plane(r, object, rec);
	else if (object->type == CO)
		hit_result = hit_cone(r, object, rec);
	else if (object->type == CU)
		hit_result = check_rotate_cube(r, object, rec);
	else if (object->type == PY)
		hit_result = check_rotate_pyramid(r, object, rec);
	return (hit_result);
}

int			hit(t_ray *r, t_objects *objects, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	int				hit_anything;

	tmp_rec = *rec;
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(r, objects, &tmp_rec))
		{
			hit_anything = TRUE;
			tmp_rec.t_max = tmp_rec.t;
			*rec = tmp_rec;
			rec->obj = objects;
		}
		objects = objects->next;
	}
	return (hit_anything);
}
