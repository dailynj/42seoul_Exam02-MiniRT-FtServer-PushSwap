/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:16:58 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 05:44:56 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "mlx.h"

/*
** filter type
*/

# define DEFAULT 0
# define SEPHIA	1
# define RED 2
# define GREEN 3
# define BLUE 4
# define BNW 5

/*
** light on/off
*/

# define ON 1
# define OFF 0

/*
** object type
*/

# define PARELLEL_LIGHT -1
# define SPOT_LIGHT 0
# define SP 1
# define PL 2
# define TR 3
# define CY 4
# define SQ 5
# define CO 6
# define CU 7
# define PY 8
# define CAM 20
# define IMAGE 100

/*
**	object texture
*/

# define DEF 10
# define CHECK 11
# define WAVE 12
# define RAINBOW 13

/*
** axis align
*/

# define X 100
# define Y 101
# define Z 102

/*
** multithreading
*/

# define COUNT 20

/*
** common structure
*/

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef t_vec	t_point;
typedef t_vec	t_color;

typedef struct	s_matrix44
{
	double		x[4][4];
	t_vec		rotate_deg;
}				t_matrix44;

/*
**	light structure
*/

typedef struct	s_spot_light
{
	t_point		p;
	t_color		color;
	double		brightness;
}				t_spot_light;

typedef struct	s_parallel_light
{
	t_vec		dir;
	t_color		albedo;
}				t_parallel_light;

/*
** object structures
*/

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_point		point;
	t_vec		n;
	t_color		color;
}				t_plane;

typedef struct	s_triangle
{
	t_point		p[3];
	t_vec		n;
	t_color		color;
}				t_triangle;

typedef struct	s_cylinder
{
	t_point		p;
	t_vec		vec;
	t_color		color;
	double		radius;
	double		len;
}				t_cylinder;

typedef struct	s_square
{
	t_point		p;
	t_vec		n;
	t_color		color;
	t_point		min;
	t_point		max;
	double		side_len;
}				t_square;

typedef	struct	s_cone
{
	t_point		p;
	t_color		color;
	t_vec		axis;
	double		height;
	double		angle;
}				t_cone;

typedef struct	s_cube
{
	t_point		p;
	double		len;
	t_square	*sq[6];
}				t_cube;

typedef struct	s_pyramid
{
	t_point		p;
	double		len;
	t_triangle	*tr[4];
	t_square	*sq;
}				t_pyramid;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct	s_texture
{
	int			type;
	double		density;
	t_color		albedo;
	t_data		*img;
}				t_texture;

/*
** scene structures
*/

typedef struct	s_cam_ray
{
	t_vec		u;
	t_vec		v;
	t_vec		w;
	t_vec		vup;
}				t_cam_ray;

typedef struct	s_objects
{
	int			type;
	void		*object;
	void		*next;
	t_texture	*texture;
	t_matrix44	*rotate;
	t_matrix44	*rotate_normal;
}				t_objects;

typedef struct	s_canvas
{
	int			width;
	int			height;
	double		ratio;
}				t_canvas;

typedef struct	s_camera
{
	double		hfov;
	t_point		origin;
	t_point		dir;
	t_vec		horizontal;
	t_vec		vertical;
	t_vec		focal;
	t_point		leftbottom;
}				t_camera;

typedef struct	s_ray
{
	t_point		origin;
	t_vec		dir;
}				t_ray;

typedef struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	t_color		color;
	t_objects	*obj;
	t_texture	*texture;
	int			front_face;
	double		t;
	double		t_min;
	double		t_max;
	double		u;
	double		v;
	int			type;
}				t_hit_record;

typedef struct	s_global
{
	t_color		ambient;
	int			samples_per_pixel;
	int			filter_type;
}				t_global;

typedef struct	s_scene
{
	t_global	global;
	t_canvas	canvas;
	t_objects	*cam_list;
	t_camera	*cam_onair;
	t_objects	*objs;
	t_objects	*background;
	t_data		*img;
}				t_scene;

typedef	struct	s_cntl
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
	t_objects	*selected;
	t_data		*img;
	int			mode;
	int			light_on;
	int			rotate_on;
	int			texture_on;
}				t_cntl;

typedef struct	s_pth_data
{
	int			lane;
	int			count;
	int			progress;
	t_cntl		*c;
}				t_pth_data;

typedef struct	s_tr_set
{
	t_vec		p;
	t_vec		c0;
	t_vec		c1;
	t_vec		c2;
	t_vec		vp;
	t_vec		r0_p0;
	double		t;
	double		denominator;
}				t_tr_set;

typedef struct	s_sp_set
{
	t_vec		oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
}				t_sp_set;

typedef struct	s_disc_set
{
	double		t;
	double		denom;
	t_point		to_hit;
	t_point		p;
}				t_disc_set;

typedef struct	s_cy_set
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	double		len;
	t_vec		delp;
	t_point		pa;
	t_point		p;
	t_vec		n;
}				t_cy_set;

typedef struct	s_light_set
{
	t_color		diffuse;
	t_color		specular;
	t_vec		light_dir;
	t_vec		unit_light_dir;
	t_vec		view_dir;
	t_vec		reflect_dir;
	t_vec		unit_norm;
	t_ray		to_light_ray;
	double		lux;
	double		distance_attenuation;
}				t_light_set;

typedef struct	s_diffuse
{
	double		kd;
	t_color		strength;
}				t_diffuse;

typedef struct	s_specular
{
	double		ks;
	double		ksn;
	double		focus;
	t_color		strength;
}				t_specular;

typedef struct	s_co_set
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	double		len;
	double		cosa;
	double		sina;
	t_vec		delp;
	t_point		pa;
	t_point		p;
	t_vec		n;
}				t_co_set;

#endif
