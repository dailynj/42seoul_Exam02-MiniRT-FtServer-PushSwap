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

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define LIGHT_POINT 1
# define FALSE 0
# define TRUE 1
# define SP 0

typedef struct s_vec t_vec;
typedef struct s_vec t_color;
typedef struct s_vec t_point;
typedef int			 t_bool;
typedef int			t_object_type;

// 벡터 구조체
struct					s_vec {
    double				x;
    double				y;
    double				z;
};

// mlx 구조체
typedef struct			s_vars {
	void				*mlx;
	void				*win;
}						t_vars;

// image data 구조체
typedef struct			s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

// ray 구조체
typedef struct			s_ray{
	t_vec				origin;
	t_vec				dir;
}						t_ray;

// hit_record 구조체
typedef struct			s_hit_record
{
	t_vec				p;
	t_vec				normal;
	double				tmin;
	double				tmax;
	double				t;
	int					front_face;
	t_color				albedo;
}						t_hit_record;

typedef struct			s_sphere{
	t_vec				center;
	double				radius;
	double				radius2;
}						t_sphere;

typedef		struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color			albedo;
}					t_object;

typedef struct s_light
{
	t_vec		origin;
	t_color		light_color; 
	double		bright_ratio;
}				t_light;

#endif