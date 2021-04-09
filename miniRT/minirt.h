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

#include "key_codes.h"
#include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>
// # include <pthread.h>
// # include <fcntl.h>

// 벡터 구조체
typedef struct  s_vector {
    double      x;
    double      y;
    double      z;
}               t_vector;

// mlx 구조체
typedef struct s_vars {
    void	*mlx;
	void	*win;
}               t_vars;

//이미지의 정보를 나타내는 변수를 저장한 구조체
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
	t_vector	orig;
	t_vector	dir;
}				t_ray;

// color 구조체
typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

// vector_operation.c
t_vector		vec3(double _x, double _y, double _z);
double          vec_length(t_vector vector);
t_vector        plus_two_vector(t_vector vector1, t_vector vector2);
t_vector        minus_two_vector(t_vector vector1, t_vector vector2);
t_vector        mul_two_vector(t_vector vector1, t_vector vector2);
t_vector        mul_num_vector(double t, t_vector vector1);
t_vector        div_num_vector(double t, t_vector vector1);
double          dot_product(t_vector vector1, t_vector vector2);
t_vector        cross_product(t_vector vector1, t_vector vector2);
t_vector        unit_vector(t_vector vector1);

// ray.c
t_ray			ray(t_vector _orig, t_vector _dir);
t_vector		ray_at(t_ray ray, double t);

//color.c
t_color			color(double r, double g, double b);
int				write_color(int t, t_color pixel_color);
t_color			ray_color(t_ray ray);
t_color			plus_two_color(t_color color1, t_color color2);
t_color			mul_num_color(double t, t_color color);
int				color_to_trgb(t_color color);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

#endif
