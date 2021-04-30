/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:10:18 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 14:09:22 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_matrix44		transpose(t_matrix44 *orig)
{
	t_matrix44	new;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			new.x[i][j] = orig->x[j][i];
		}
	}
	return (new);
}

static void		matrix_inverse_error(void)
{
	perror("Matrix Inverse error\n");
	exit(1);
}

static void		gauss_jordan(int *i, t_matrix44 *a, t_matrix44 *inv)
{
	double		ratio;

	i[0] = -1;
	while (++i[0] < 4)
	{
		if (a->x[i[0]][i[0]] == 0.0)
			matrix_inverse_error();
		i[1] = -1;
		while (++i[1] < 4)
		{
			if (i[0] != i[1])
			{
				ratio = a->x[i[1]][i[0]] / a->x[i[0]][i[0]];
				i[2] = -1;
				while (++i[2] < 4)
				{
					a->x[i[1]][i[2]] = a->x[i[1]][i[2]]
							- ratio * a->x[i[1]][i[2]];
					inv->x[i[1]][i[2]] = inv->x[i[1]][i[2]]
							- ratio * inv->x[i[0]][i[2]];
				}
			}
		}
	}
}

t_matrix44		*inverse(t_matrix44 a)
{
	t_matrix44	*inv;
	int			i[3];

	inv = m_identity();
	gauss_jordan(i, inv, &a);
	i[0] = -1;
	while (++i[0] < 4)
	{
		i[1] = -1;
		while (++i[1] < 4)
			inv->x[i[0]][i[1]] = inv->x[i[0]][i[1]] / a.x[i[0]][i[1]];
	}
	return (inv);
}

t_matrix44		*rotate_normal(t_matrix44 *rotate)
{
	t_matrix44 *rotate_normal;

	if (rotate == NULL)
		return (NULL);
	rotate_normal = inverse(*rotate);
	return (rotate_normal);
}
