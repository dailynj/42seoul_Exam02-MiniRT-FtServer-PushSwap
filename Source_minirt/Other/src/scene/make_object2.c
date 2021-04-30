/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:19:22 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:22:03 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	square_min_max_set(t_point *p, t_square *sq, double half_side)
{
	if (is_aligned(sq->n) == X)
	{
		sq->min = v_minus(*p, vec(0, half_side, half_side));
		sq->max = v_plus(*p, vec(0, half_side, half_side));
	}
	else if (is_aligned(sq->n) == Y)
	{
		sq->min = v_minus(*p, vec(half_side, 0, half_side));
		sq->max = v_plus(*p, vec(half_side, 0, half_side));
	}
	else if (is_aligned(sq->n) == Z)
	{
		sq->min = v_minus(*p, vec(half_side, half_side, 0));
		sq->max = v_plus(*p, vec(half_side, half_side, 0));
	}
	else
		exit(0);
}

t_square	*square(t_point p, t_vec normal, double side_len)
{
	t_square		*square;

	if (!(square = (t_square *)malloc(sizeof(t_square))))
		malloc_error();
	square->p = p;
	square->n = v_normalize(normal);
	square->side_len = side_len;
	square_min_max_set(&p, square, side_len / 2);
	return (square);
}

t_cone		*cone(t_point p, t_vec axis, double angle, double height)
{
	t_cone			*cone;

	if (!(cone = (t_cone *)malloc(sizeof(t_cone))))
		malloc_error();
	cone->p = p;
	cone->axis = v_normalize(axis);
	cone->angle = angle;
	cone->height = height;
	return (cone);
}

t_cube		*cube(t_point p, double len)
{
	t_cube			*cube;
	double			half;

	if (!(cube = (t_cube *)malloc(sizeof(t_cube))))
		malloc_error();
	half = len / 2;
	cube->p = p;
	cube->len = len;
	cube->sq[0] = square(vec(p.x + half, p.y, p.z), vec(1, 0, 0), len);
	cube->sq[1] = square(vec(p.x - half, p.y, p.z), vec(-1, 0, 0), len);
	cube->sq[2] = square(vec(p.x, p.y + half, p.z), vec(0, 1, 0), len);
	cube->sq[3] = square(vec(p.x, p.y - half, p.z), vec(0, -1, 0), len);
	cube->sq[4] = square(vec(p.x, p.y, p.z + half), vec(0, 0, 1), len);
	cube->sq[5] = square(vec(p.x, p.y, p.z - half), vec(0, 0, -1), len);
	return (cube);
}

t_pyramid	*pyramid(t_point t, double len)
{
	t_pyramid		*pyramid;
	t_point			p[4];
	double			half;

	if (!(pyramid = (t_pyramid *)malloc(sizeof(t_pyramid))))
		malloc_error();
	half = len / 2.0;
	pyramid->p = t;
	p[0] = point(t.x - half, t.y - (half * sqrt(2.0)), t.z - half);
	p[1] = point(t.x - half, t.y - (half * sqrt(2.0)), t.z + half);
	p[2] = point(t.x + half, t.y - (half * sqrt(2.0)), t.z + half);
	p[3] = point(t.x + half, t.y - (half * sqrt(2.0)), t.z - half);
	pyramid->len = len;
	pyramid->tr[0] = triangle(t, p[0], p[1]);
	pyramid->tr[1] = triangle(t, p[1], p[2]);
	pyramid->tr[2] = triangle(t, p[2], p[3]);
	pyramid->tr[3] = triangle(t, p[3], p[0]);
	pyramid->sq = square(point(t.x, t.y - half * sqrt(2.0), t.z),
						vec(0, -1, 0), len);
	return (pyramid);
}
