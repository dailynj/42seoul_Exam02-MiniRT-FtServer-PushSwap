/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:34:00 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:20:56 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_sphere	*sphere(t_point center, double radius)
{
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		malloc_error();
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

t_plane		*plane(t_point point, t_vec normal)
{
	t_plane		*plane;

	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		malloc_error();
	plane->point = point;
	plane->n = normal;
	return (plane);
}

t_triangle	*triangle(t_point a, t_point b, t_point c)
{
	t_triangle	*triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		malloc_error();
	triangle->p[0] = a;
	triangle->p[1] = b;
	triangle->p[2] = c;
	triangle->n = v_normalize(v_cross(v_minus(b, a), v_minus(c, a)));
	return (triangle);
}

t_cylinder	*cylinder(t_point p, t_vec cen_vec, double diameter, double height)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		malloc_error();
	cylinder->p = p;
	cylinder->vec = cen_vec;
	cylinder->radius = diameter / 2;
	cylinder->len = height;
	return (cylinder);
}
