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

// 벡터 구조체
typedef struct  s_vec {
    double      x;
    double      y;
    double      z;
}               t_vec;

// mlx 구조체
typedef struct s_vars {
    void	*mlx;
	void	*win;
}               t_vars;

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

// ray 구조체
typedef struct	s_ray{
	t_vec	orig;
	t_vec	dir;
}				t_ray;

// color 구조체
typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

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

// sphere 구조체
// typedef struct			s_data_sphere
// {
// 	t_vec				center;
// 	double				radius;
// 	t_color				diff_color;
// 	t_color				spec_color;
// 	t_color				ambi_color;
// }						t_data_sphere;

// vector_operation.c
t_vec		vec3(double _x, double _y, double _z);
double		vec_length(t_vec vector);
t_vec		vec_add(t_vec vector1, t_vec vector2);
t_vec		vec_minus(t_vec vector1, t_vec vector2);
t_vec		vec_mul(t_vec vector1, t_vec vector2);
t_vec		vec_mul_num(double t, t_vec vector1);
t_vec		vec_div(double t, t_vec vector1);
double		vec_dot(t_vec vector1, t_vec vector2);
t_vec		vec_cross(t_vec vector1, t_vec vector2);
t_vec		vec_unit(t_vec vector1);

// ray.c
t_ray		ray(t_vec _orig, t_vec _dir);
t_vec		ray_at(t_ray ray, double t);

//color.c
t_color			color(double r, double g, double b);
int				write_color(int t, t_color pixel_color);
t_vec			ray_color(t_ray ray);
t_color			color_add(t_color color1, t_color color2);
t_color			color_mul_num(double t, t_color color);
int				color_to_trgb(t_color color);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

//sphere.c
void		set_face_normal(t_ray *r, t_hit_record *rec);
int			hit_sphere(t_vec center, double radius, t_ray ray, t_hit_record *rec);

#endif
