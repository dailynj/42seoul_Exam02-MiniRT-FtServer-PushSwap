/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:48:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 03:09:12 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# include "scene.h"
# include "trace.h"
# include "utils.h"
# include "parse.h"
# include "bitmap.h"
# include "key_macro.h"

# define DEFM 0
# define OBJM 1
# define CAMM 2
# define LIGM 3
# define FILM 4

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		cntl_init(t_cntl *cntl, char *filepath);
void		cntl_display_resolution(t_cntl *cntl);
void		cntl_init_except_resolution(t_cntl *cntl, char *argv);
int			cntl_click_x(void);
void		my_mlx_control(t_cntl *cntl);
int			cntl_close(void);
int			cntl_mouse_click(int button, int x, int y, t_cntl *cntl);
void		rendor_mode(t_cntl *cntl);
void		cntl_filter_change(int keycode, t_cntl *cntl);
void		console_message(int mode);

/*
**	object control
*/

void		cntl_object_translate(int keycode, t_cntl *cntl);
void		translate_sphere(int keycode, t_cntl *cntl);
void		translate_plane(int keycode, t_cntl *cntl);
void		translate_square(int keycode, t_cntl *cntl);
void		translate_cylinder(int keycode, t_cntl *cntl);
void		translate_triangle(int keycode, t_cntl *cntl);
void		translate_cone(int keycode, t_cntl *cntl);
void		translate_cube(int keycode, t_cntl *cntl);
void		translate_cube_x(int keycode, t_cntl *cntl);
void		translate_cube_y(int keycode, t_cntl *cntl);
void		translate_cube_z(int keycode, t_cntl *cntl);
void		pyramid_z_move_neg(t_cntl *c);
void		pyramid_z_move_pos(t_cntl *c);
void		pyramid_y_move_neg(t_cntl *c);
void		pyramid_y_move_pos(t_cntl *c);
void		pyramid_x_move_neg(t_cntl *c);
void		pyramid_x_move_pos(t_cntl *c);
void		translate_pyramid(int keycode, t_cntl *cntl);
void		cntl_object_scale(int keycode, t_cntl *cntl);
void		scale_sphere(int keycode, t_cntl *cntl);
void		scale_square(int keycode, t_cntl *cntl);
void		scale_cylinder(int keycode, t_cntl *cntl);
void		scale_cone(int keycode, t_cntl *cntl);
void		scale_cube(int keycode, t_cntl *cntl);
void		scale_pyramid(int keycode, t_cntl *cntl);
void		cntl_object_deselect(t_cntl *cntl);
void		cntl_object_select(int button, int x, int y, t_cntl *cntl);
void		cntl_object(int keycode, t_cntl *cntl);
void		cntl_object_rotate_on_and_off(t_cntl *cntl);
void		cntl_object_rotate_sq_cu_py(t_cntl *cntl, int keycode);
void		cntl_object_rotate(int keycode, t_cntl *cntl);
void		rotate_cylinder(int keycode, t_cntl *cntl);
void		rotate_cone(int keycode, t_cntl *cntl);
void		cntl_object_texture(int keycode, t_cntl *cntl);

/*
**	light control
*/

void		cntl_light_mode_on(t_cntl *cntl);
void		cntl_light_mode_off(t_cntl *cntl);
void		cntl_light_select(t_cntl *cntl);
void		cntl_light_on_and_off(t_cntl *cntl);
void		cntl_light_translate(int keycode, t_cntl *cntl);
void		cntl_light_bright_up(t_cntl *cntl);
void		cntl_light_bright_down(t_cntl *cntl);
void		cntl_light(t_cntl *cntl, int keycode);

/*
**	camera control
*/

void		cntl_camera_on(t_cntl *cntl);
void		cntl_camera_off(t_cntl *cntl);
void		cntl_select_camera(t_cntl *cntl);
void		cntl_camera_translate(int keycode, t_cntl *cntl);
void		cntl_camera_hfov(int keycode, t_cntl *cntl);
void		cntl_camera(t_cntl *cntl, int keycode);
void		cntl_cam_rotate(int button, t_cntl *cntl);

/*
** save
*/

t_bmph		bmp_get_header(t_scene *scene);
void		bmp_save_direct(t_cntl *cntl);
void		cntl_save(t_cntl *cntl);
void		write_bmp(t_data *image, t_scene *scene, int fd);

#endif
