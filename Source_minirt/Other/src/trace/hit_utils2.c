/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 04:51:05 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 04:51:46 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void		object2world_rec(t_hit_record *rec, t_vec *offset,
								t_matrix44 *r, t_matrix44 *r_n)
{
	t_matrix44 r_inv;

	r_inv = transpose(r);
	rec->p = m_mult_v(rec->p, 0, &r_inv);
	rec->normal = m_mult_v(rec->normal, 0, r_n);
	rec->p = v_plus(rec->p, *offset);
}

void		get_record(t_hit_record *rec, double root,
						t_objects *obj, t_ray *r)
{
	rec->texture = obj->texture;
	rec->t = root;
	rec->p = at(root, *r);
}
