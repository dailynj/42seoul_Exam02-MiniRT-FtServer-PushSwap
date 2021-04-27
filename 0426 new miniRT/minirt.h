/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:20:32 by najlee            #+#    #+#             */
/*   Updated: 2021/04/09 20:04:31 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "key_codes.h"
# include "structures.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
// # include <pthread.h>
// # include <fcntl.h>

//ray.c
t_vec       ray_at(t_ray *ray, double t);

//vec.c
t_vec       vec(double x, double y, double z);
double      vec_length(t_vec vector);
t_vec       vec_add(t_vec vector1, t_vec vector2);
t_vec       vec_minus(t_vec vector1, t_vec vector2);
t_vec       vec_mul(t_vec vector1, t_vec vector2);
t_vec       vec_mul_num(double t, t_vec vector1);
t_vec       vec_div(double t, t_vec vector1);
double      vec_dot(t_vec vector1, t_vec vector2);
t_vec       vec_cross(t_vec vector1, t_vec vector2);
t_vec       vec_unit(t_vec vector1);

//color.c
t_color     color(double r, double g, double b);
int         write_color(int t, t_color pixel_color);
t_vec       ray_color(t_ray r, t_sphere *sphere);

// sphere.c
t_sphere	sphere(t_vec center, double radius);
t_bool      hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
void        set_face_normal(t_ray *ray, t_hit_record *rec);

//point.c
t_vec       point3(double x, double y, double z);

#endif
