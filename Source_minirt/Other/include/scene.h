/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:16:18 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 03:14:25 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "mlx.h"
# include "utils.h"

void				scene_init(t_scene *scene);
t_camera			*cam_init(t_point lookfrom, t_vec lookdir, double hfov);
void				set_cam(t_camera *camera, t_scene *scene);
void				render_phong(t_cntl *cntl);
void				render_preview(t_cntl *cntl);
void				render(t_cntl *cntl);

t_spot_light		*spot_light(t_point point, double ratio, t_color color);
t_parallel_light	*parallel_light(t_vec dir, t_color color);

t_texture			*texture(int texture_type, t_color albedo);
t_texture			*texture_img(t_data *img);
t_sphere			*sphere(t_point center, double radius);
t_plane				*plane(t_point point, t_vec normal);
t_triangle			*triangle(t_point p1, t_point p2, t_point p3);
t_cylinder			*cylinder(t_point p, t_vec cen_vec, double diameter,
							double height);
t_plane				*plane(t_point p, t_vec normal);
t_square			*square(t_point p, t_vec normal, double side_len);
t_cone				*cone(t_point p, t_vec axis, double angle, double height);
t_cube				*cube(t_point p, double side_len);
t_pyramid			*pyramid(t_point p, double len);

#endif
