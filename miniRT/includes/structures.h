/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:20:32 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 01:15:36 by najlee           ###   ########.fr       */
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

struct			s_vec
{
	double		x;
	double		y;
	double		z;
};

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_ray
{
	t_vec		origin;
	t_vec		dir;
}				t_ray;

typedef struct	s_camera
{
	t_point		orig;
	t_vec		normal;
	double		vp_h;
	double		vp_w;
	t_vec		horiz;
	t_vec		vertical;
	double		focal_len;
	t_point		left_bottom;
}				t_cam;

typedef struct	s_canv
{
	double		wid;
	double		heig;
	double		aspect_ratio;
}				t_canv;

typedef struct	s_hit_record
{
	t_vec		p;
	t_vec		normal;
	double		tmin;
	double		tmax;
	double		t;
	double		t2;
	int			front_face;
	t_color		albedo;
}				t_hit_record;

typedef struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color			albedo;
}				t_object;

typedef struct	s_light
{
	t_vec		origin;
	t_color		light_color;
	double		bright_ratio;
}				t_light;

typedef struct	s_scene
{
	t_canv			canv;
	t_cam			**c_arr;
	int				c_num;
	int				camera_idx;
	t_object		*world;
	t_object		*light;
	t_color			ambient;
	t_ray			ray;
	t_hit_record	rec;
}				t_scene;

typedef struct	s_cntl
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
	t_data		*image;
}				t_cntl;

typedef struct	s_sphere
{
	t_vec		center;
	double		radius;
	double		radius2;
}				t_sphere;

typedef struct	s_plane
{
	t_vec		point;
	t_vec		normal;
}				t_plane;

typedef struct	s_square
{
	t_vec		point;
	t_vec		normal;
	double		length;
}				t_square;

typedef struct	s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_vec		normal;
}				t_triangle;

typedef struct	s_cylinder
{
	t_point		point;
	t_vec		normal;
	double		radius;
	double		heig;
}				t_cylinder;

# pragma pack(push, 1)

typedef	struct	s_color2
{
	unsigned char	z;
	unsigned char	y;
	unsigned char	x;
}				t_color2;

typedef	struct	s_fileheader
{
	unsigned char	sign1;
	unsigned char	sign2;
	unsigned int	file_size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	start_bmp;
}				t_fileheader;

typedef	struct	s_infoheader
{
	unsigned int	size;
	unsigned int	witdh;
	unsigned int	heig;
	unsigned short	planes;
	unsigned short	bitcount;
	unsigned int	compression;
	unsigned int	sizeimage;
	unsigned int	x_pelspermeter;
	unsigned int	y_pelspermeter;
	unsigned int	color_used;
	unsigned int	color_important;
}				t_infoheader;

typedef	struct	s_bmp
{
	t_fileheader	file_h;
	t_infoheader	info_h;
}				t_bmp;

# pragma pack(pop)

#endif
