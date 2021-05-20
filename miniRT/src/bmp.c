/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:55:20 by najlee            #+#    #+#             */
/*   Updated: 2021/05/17 16:55:21 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bmp		bmp_set_header(t_scene *scene)
{
	t_bmp	bmp;

	bmp.file_h.sign1 = 'B';
	bmp.file_h.sign2 = 'M';
	bmp.file_h.file_size = 14 + 40 +
			(int)(scene->canv.wid) * (int)(scene->canv.heig) * 4;
	bmp.file_h.reserved1 = 0;
	bmp.file_h.reserved2 = 0;
	bmp.file_h.start_bmp = 14 + 40;
	bmp.info_h.size = 40;
	bmp.info_h.witdh = (int)(scene->canv.wid);
	bmp.info_h.heig = (int)(scene->canv.heig);
	bmp.info_h.planes = 1;
	bmp.info_h.bitcount = 24;
	bmp.info_h.compression = 0;
	bmp.info_h.sizeimage = (4 * ((int)(scene->canv.wid + 3) / 4)) *
									(int)(scene->canv.heig);
	bmp.info_h.x_pelspermeter = (int)(scene->canv.wid);
	bmp.info_h.y_pelspermeter = (int)(scene->canv.heig);
	bmp.info_h.color_used = 0xffffff;
	bmp.info_h.color_important = 0;
	return (bmp);
}

t_color2	color2(double r, double g, double b)
{
	t_color2	c;

	c.x = r * 255.0;
	c.y = g * 255.0;
	c.z = b * 255.0;
	return (c);
}

int			mlx_save_image(t_cntl *cntl, int i)
{
	int			j;
	int			fd;
	t_bmp		bmp;
	t_color		pixel_color;
	t_color2	tmp_color;

	printf("** START SAVE **\n");
	fd = open("miniRT.bmp", O_WRONLY | O_CREAT, 0644);
	bmp = bmp_set_header(cntl->scene);
	write(fd, &bmp, 54);
	while (++i < cntl->scene->canv.heig)
	{
		j = -1;
		while (++j < cntl->scene->canv.wid)
		{
			cntl->scene->ray = ray_primary(cntl->scene->c_arr[0], (double)j
	/ (cntl->scene->canv.wid - 1), (double)i / (cntl->scene->canv.heig - 1));
			pixel_color = ray_color(cntl->scene);
			tmp_color = color2(pixel_color.x, pixel_color.y, pixel_color.z);
			write(fd, &tmp_color, 3);
		}
	}
	close(fd);
	printf("** FINISH SAVE **\n");
	return (0);
}
