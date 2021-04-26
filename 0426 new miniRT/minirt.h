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
# define FALSE 0
# define TRUE 1

#include "key_codes.h"
#include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

// # include <stdio.h>
// # include <pthread.h>
// # include <fcntl.h>

// typedef enum	e_bool {
// 	FALSE,
// 	TRUE
// }				t_bool;

typedef struct s_vec t_vec;
typedef struct s_vec t_color;
typedef struct s_vec t_point;

// 벡터 구조체
struct  s_vec {
    double      x;
    double      y;
    double      z;
};

// mlx 구조체
typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

// image data 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

// ray 구조체
typedef struct	s_ray{
	t_vec	origin;
	t_vec	dir;
}				t_ray;

// hit_record 구조체
typedef struct			s_hit_record
{
	t_vec				p;
	t_vec				normal;
	double				tmin;
	double				tmax;
	double				t;
	int					front_face;
}						t_hit_record;

//ray.c
t_vec	ray_at(t_ray *ray, double t);

//vec.c
t_vec vec(double x, double y, double z);
double          vec_length(t_vec vector);
t_vec        vec_add(t_vec vector1, t_vec vector2);
t_vec        vec_minus(t_vec vector1, t_vec vector2);
t_vec        vec_mul(t_vec vector1, t_vec vector2);
t_vec        vec_mul_num(double t, t_vec vector1);
t_vec        vec_div(double t, t_vec vector1);
double          vec_dot(t_vec vector1, t_vec vector2);
t_vec        vec_cross(t_vec vector1, t_vec vector2);
t_vec        vec_unit(t_vec vector1);

//color.c
t_color		color(double r, double g, double b);
int write_color(int t, t_color pixel_color);
t_vec   	ray_color(t_ray r);

// sphere.c
int hit_sphere(t_vec center, double radius, t_ray r);

//point.c
t_vec point3(double x, double y, double z);
#endif
