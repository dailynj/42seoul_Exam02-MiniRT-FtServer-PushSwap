/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:20:32 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:40:11 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define LIGHT_POINT 1
# define EPSILON 1e-6
# define FALSE 0
# define TRUE 1
# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4

# define O_RDONLY 0x0000
# define BUFFER_SIZE 4000000

typedef struct s_vec	t_vec;
typedef struct s_vec	t_color;
typedef struct s_vec	t_point;
typedef int				t_bool;
typedef int				t_object_type;

struct					s_vec
{
	double					x;
	double					y;
	double					z;
};

typedef struct			s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct			s_ray
{
	t_vec				origin;
	t_vec				dir;
}						t_ray;

typedef struct			s_camera
{
	t_point					orig;
	t_vec					normal;
	double					viewport_h;
	double					viewport_w;
	t_vec					horizontal;
	t_vec					vertical;
	double					focal_len;
	t_point					left_bottom;
}						t_camera;

typedef struct			s_canvas
{
	double		width;
	double		height;
	double	aspect_ratio;
}						t_canvas;

typedef struct			s_hit_record
{
	t_vec					p;
	t_vec					normal;
	double					tmin;
	double					tmax;
	double					t;
	double					t2;
	int						front_face;
	t_color					albedo;
}						t_hit_record;

typedef struct			s_object
{
	t_object_type			type;
	void					*element;
	void					*next;
	t_color					albedo;
}						t_object;

typedef struct			s_light
{
	t_vec					origin;
	t_color					light_color;
	double					bright_ratio;
}						t_light;

typedef struct			s_scene
{
	t_canvas				canvas;
	t_camera				*camera_arr;
	int						camera_num;
	t_object				*world;
	t_object				*light;
	t_color					ambient;
	t_ray					ray;
	t_hit_record			rec;
}						t_scene;

typedef struct			s_cntl
{
	void					*mlx;
	void					*win;
	t_scene					*scene;
}						t_cntl;

typedef struct			s_sphere
{
	t_vec					center;
	double					radius;
	double					radius2;
}						t_sphere;

typedef struct			s_plane
{
	t_vec					point;
	t_vec					normal;
}						t_plane;

typedef struct			s_square
{
	t_vec					point;
	t_vec					normal;
	double					length;
}						t_square;

typedef struct			s_triangle
{
	t_point				p1;
	t_point				p2;
	t_point				p3;
	t_vec				normal;
}						t_triangle;

typedef struct			s_cylinder
{
	t_point					point;
	t_vec					normal;
	double					radius;
	double					height;
}						t_cylinder;

#endif
