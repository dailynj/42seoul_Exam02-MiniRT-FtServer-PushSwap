/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:12:22 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:07:57 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_matrix44		*m_identity(void)
{
	t_matrix44	*matrix;
	int			i;
	int			j;

	if (!(matrix = (t_matrix44 *)malloc(sizeof(t_matrix44))))
		malloc_error();
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			matrix->x[i][j] = (i == j) ? 1 : 0;
	}
	return (matrix);
}

t_matrix44		*m_move(t_point move)
{
	t_matrix44 *mtx;

	mtx = m_identity();
	mtx->x[3][0] = move.x;
	mtx->x[3][1] = move.y;
	mtx->x[3][2] = move.z;
	return (mtx);
}

t_matrix44		*m_rotate_x(double degree)
{
	t_matrix44	*mtx;
	double		theta;

	theta = deg_to_rad(degree);
	mtx = m_identity();
	mtx->x[1][1] = cos(theta);
	mtx->x[1][2] = sin(theta);
	mtx->x[2][1] = -sin(theta);
	mtx->x[2][2] = cos(theta);
	return (mtx);
}

t_matrix44		*m_rotate_y(double degree)
{
	t_matrix44	*mtx;
	double		theta;

	theta = deg_to_rad(degree);
	mtx = m_identity();
	mtx->x[0][0] = cos(theta);
	mtx->x[0][2] = -sin(theta);
	mtx->x[2][0] = sin(theta);
	mtx->x[2][2] = cos(theta);
	return (mtx);
}

t_matrix44		*m_rotate_z(double degree)
{
	t_matrix44	*mtx;
	double		theta;

	theta = deg_to_rad(degree);
	mtx = m_identity();
	mtx->x[0][0] = cos(theta);
	mtx->x[0][1] = sin(theta);
	mtx->x[1][0] = -sin(theta);
	mtx->x[1][1] = cos(theta);
	return (mtx);
}
