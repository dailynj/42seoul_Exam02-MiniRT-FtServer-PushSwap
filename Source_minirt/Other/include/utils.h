/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:43 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 03:17:17 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define PI 3.1415926535897932385

# include "structures.h"
# include "parse.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/*
** vector utils
*/

t_point			point(double x, double y, double z);
t_vec			vec(double x, double y, double z);
void			input_elements(t_vec *vec, double x, double y, double z);
t_vec			v_plus(t_vec vec1, t_vec vec2);
t_vec			v_minus(t_vec vec1, t_vec vec2);
t_vec			v_multiply(t_vec vec1, double f);
t_vec			v_multiply_2(t_vec vec1, t_vec vec2);
t_vec			v_normalize(t_vec vec);
t_vec			v_cross(t_vec vec1, t_vec vec2);
double			v_dot(t_vec vec1, t_vec vec2);
double			v_len_squared(t_vec vec);
double			v_len(t_vec vec);
t_vec			v_min(t_vec vec1, t_vec vec2);

/*
** matrix utils
*/

t_matrix44		*m_identity(void);
t_matrix44		*m_move(t_point move);
t_matrix44		*m_rotate_x(double degree);
t_matrix44		*m_rotate_y(double degree);
t_matrix44		*m_rotate_z(double degree);
t_vec			m_mult_v(t_vec vec, double h, t_matrix44 *mtx);
void			m_mult_m(t_matrix44 *dst, t_matrix44 *src);
t_matrix44		*rotate(t_vec rotate);
t_matrix44		transpose(t_matrix44 *orig);
t_matrix44		*inverse(t_matrix44 a);
t_matrix44		*rotate_normal(t_matrix44 *rotate);

/*
** object utils
*/

t_objects		*obj_new(int obj_type, void *object, t_texture *texture);
void			obj_add_back(t_objects **lst, t_objects *new);

/*
** color utils
*/

t_color			color(double x, double y, double z);
int				color_to_int(t_color pixel_color);

/*
** common utils
*/

double			deg_to_rad(double degrees);
int				is_aligned(t_vec vec);
double			random_double(void);
double			saturate(double value);
int				saturate_min_max_int(int value, int min, int max);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);

#endif
