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

t_bmp	bmp_set_header(t_scene *scene)
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
	bmp.info_h.heig = -(int)(scene->canv.heig);
	bmp.info_h.planes = 1;
	bmp.info_h.bitcount = 32;
	bmp.info_h.compression = 0;
	bmp.info_h.sizeimage = 4 * (int)(scene->canv.wid) *
									(int)(scene->canv.heig);
	bmp.info_h.x_pelspermeter = (int)(scene->canv.wid);
	bmp.info_h.y_pelspermeter = (int)(scene->canv.heig);
	bmp.info_h.color_used = 0xffffff;
	bmp.info_h.color_important = 0;
	return (bmp);
}

int		mlx_save_image(t_cntl *cntl)
{
	int			i;
	int			fd;
	t_bmp		bmp;

	i = 0;
	printf("** START SAVE **\n");
	fd = open("miniRT.bmp", O_CREAT | O_WRONLY | O_TRUNC);
	bmp = bmp_set_header(cntl->scene);
	write(fd, &bmp, 54);
	while (i < (cntl->image[0].line_length / 4) *
						(int)(cntl->scene->canv.heig))
	{
		if (i % (cntl->image[0].line_length / 4) <
								(int)(cntl->scene->canv.wid))
			write(fd, &cntl->image[0].addr[i * 4], 4);
		++i;
	}
	close(fd);
	printf("** FINISH SAVE **\n");
	return (0);
}
