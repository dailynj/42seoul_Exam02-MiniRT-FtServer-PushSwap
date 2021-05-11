/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:06:04 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 01:11:41 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vec			m_mult_v(t_vec vec, double h, t_matrix44 *mtx)
{
	t_vec	new;

	if (mtx == NULL)
		return (vec);
	new.x = vec.x * mtx->x[0][0] + vec.y * mtx->x[1][0]
			+ vec.z * mtx->x[2][0] + h * mtx->x[3][0];
	new.y = vec.x * mtx->x[0][1] + vec.y * mtx->x[1][1]
			+ vec.z * mtx->x[2][1] + h * mtx->x[3][1];
	new.z = vec.x * mtx->x[0][2] + vec.y * mtx->x[1][2]
			+ vec.z * mtx->x[2][2] + h * mtx->x[3][2];
	return (new);
}

void			m_mult_m(t_matrix44 *dst, t_matrix44 *src)
{
	t_matrix44	new;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			new.x[i][j] = 0;
			while (++k < 4)
				new.x[i][j] += dst->x[i][k] * src->x[k][j];
		}
	}
	*dst = new;
}

t_matrix44		*rotate(t_vec rotate)
{
	t_matrix44	*result;
	t_matrix44	*rotate_y;
	t_matrix44	*rotate_z;

	result = m_rotate_x(rotate.x);
	rotate_y = m_rotate_y(rotate.y);
	rotate_z = m_rotate_z(rotate.z);
	m_mult_m(result, rotate_y);
	m_mult_m(result, rotate_z);
	free(rotate_y);
	free(rotate_z);
	result->rotate_deg = rotate;
	return (result);
}
