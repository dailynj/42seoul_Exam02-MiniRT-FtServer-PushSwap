/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:38:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 06:00:34 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "utils.h"
# include "scene.h"

# define TRUE 1
# define FALSE 0

void		set_face_normal(t_ray r, t_hit_record *rec);
t_vec		reflect(t_vec v, t_vec n);
int			is_inside(t_point p1, t_point p2, t_point p3, t_point p);
t_point		at(double t, t_ray ray);
t_ray		ray(t_point orig, t_vec dir);

int			check_shadow(t_ray *ray, t_objects *objects);
void		get_light_set(t_light_set *l, t_hit_record *rec, t_ray *r,
														t_spot_light *light);
t_diffuse	get_diffuse_strength(t_light_set l, t_color albedo);
t_specular	get_specular_strength(t_light_set l, t_color albedo,
															t_diffuse d);
t_color		phong_color_spot(t_ray *r, t_spot_light *light,
					t_hit_record *rec, t_objects *objects_for_check);
int			check_parellel_shadow(t_ray *r, t_objects *objects);
t_color		phong_color_parallel(t_ray *r, t_parallel_light *pl,
					t_hit_record *rec, t_objects *objects_for_check);
t_color		phong_color(t_ray *r, t_scene *scene, t_hit_record *rec);
t_color		check_texture(t_hit_record *rec);
t_color		checkerboard_uv(t_hit_record *rec);
t_color		checkerboard(t_hit_record *rec);
t_color		wave(t_hit_record *rec);
t_color		rainbow(t_hit_record *rec);

t_color		color_background(t_ray *r, t_scene *s, t_hit_record *rec);
t_color		albedo_skybox(t_hit_record *rec);

int			hit_sphere(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_triangle(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_cylinder(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_disc(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_plane(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_square(t_ray *r, t_objects *obj, t_hit_record *rec);
int			check_rotate_square(t_ray *ray, t_objects *obj, t_hit_record *rec);
int			hit_cone(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_cube(t_ray *r, t_objects *obj, t_hit_record *rec);
int			check_rotate_cube(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_pyramid(t_ray *r, t_objects *obj, t_hit_record *rec);
int			check_rotate_pyramid(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit_objects(t_ray *r, t_objects *obj, t_hit_record *rec);
int			hit(t_ray *r, t_objects *objects, t_hit_record *rec);
void		object2world_rec(t_hit_record *rec, t_vec *offset,
					t_matrix44 *rotate, t_matrix44 *rotate_normal);
t_color		ray_color(t_ray *r, t_scene *scene);
t_color		ray_color_preview(t_ray *r, t_scene *scene, int light_on);

void		filter(t_color *pixel_color, t_global *global);

void		get_record(t_hit_record *rec, double root,
						t_objects *obj, t_ray *r);

#endif
