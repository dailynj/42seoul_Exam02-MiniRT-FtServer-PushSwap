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



// image data 구조체
typedef struct			s_data
{
	void				*img; // image 포인터의 배열 **img 로 바꾸기 (시간이 빠르게 걸림)
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

typedef struct			s_camera
{
	t_point		orig;  // 카메라 원점(위치)
	t_vec		normal;
	double		viewport_h; // 뷰포트 세로길이
	double		viewport_w; // 뷰포트 가로길이
	t_vec		horizontal; // 수평길이 벡터
	t_vec		vertical; // 수직길이 벡터
	double		focal_len; // focal length
	t_point		left_bottom; // 왼쪽 아래 코너점
}						t_camera;

typedef struct			s_canvas
{
	int		width; //canvas width
	int		height; //canvas height;
	double	aspect_ratio; //종횡비
}						t_canvas;

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

typedef struct		s_scene
{
	t_canvas		canvas;
	t_camera		*camera_arr;
	t_object		*world;
	t_object		*light;
	t_color			ambient;
	t_ray			ray;
	t_hit_record	rec;
}					t_scene;

// mlx 구조체
typedef struct			s_cntl { 
	void				*mlx;
	void				*win;
	t_scene				*scene;
}						t_cntl;

typedef struct			s_sphere{
	t_vec				center;
	double				radius;
	double				radius2;
}						t_sphere;

typedef struct			s_plane
{
	t_vec				point;
	t_vec				normal;
}						t_plane;

typedef struct	s_square
{
	t_vec		point;
	t_vec		normal;
	double		length;
}				t_square;

typedef struct	s_triangle
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_vec		normal;
	// t_texture	*texture;
}		t_triangle;


typedef struct      s_cylinder
{
    t_point        point;
    t_vec          normal;
    double          radius;
    double          height;
}                   t_cylinder;


#endif