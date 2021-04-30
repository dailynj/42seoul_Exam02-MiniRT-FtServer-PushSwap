/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:50:41 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 02:17:59 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		write_bmp(t_data *image, t_scene *scene, int fd)
{
	int		i;

	i = 0;
	while (i < (image->line_length / 4) * scene->canvas.height)
	{
		if (i % (image->line_length / 4) < scene->canvas.width)
			write(fd, &image->addr[i * 4], 4);
		++i;
	}
}

t_bmph		bmp_get_header(t_scene *scene)
{
	int		width;
	int		height;
	t_bmph	bmph;

	width = scene->canvas.width;
	height = scene->canvas.height;
	bmph.file_h.magic1 = 'B';
	bmph.file_h.magic2 = 'M';
	bmph.file_h.size = 54 + 4 * width * height;
	bmph.file_h.reserved1 = 0;
	bmph.file_h.reserved2 = 0;
	bmph.file_h.offset = 54;
	bmph.info_h.size = 40;
	bmph.info_h.width = width;
	bmph.info_h.height = -height;
	bmph.info_h.plane = 1;
	bmph.info_h.bit_per_pixel = 32;
	bmph.info_h.compression = 0;
	bmph.info_h.size_image = 4 * width * height;
	bmph.info_h.resolution_x = width;
	bmph.info_h.resolution_y = height;
	bmph.info_h.color_used = 0xffffff;
	bmph.info_h.color_important = 0;
	return (bmph);
}

void		bmp_save_direct(t_cntl *cntl)
{
	t_bmph	bmph;
	char	*line;
	t_data	*image;
	int		fd;

	printf("TYPE FILE NAME(MUST END WITH .bmp)\n");
	get_next_line(0, &line);
	fd = open(ft_strjoin("./", line), O_WRONLY | O_CREAT | O_TRUNC, 0666);
	bmph = bmp_get_header(cntl->scene);
	write(fd, &bmph, 54);
	cntl_save(cntl);
	image = cntl->img;
	write_bmp(image, cntl->scene, fd);
	printf("[%s] WAS SAVED\n", line);
	free(line);
	close(fd);
}

void		cntl_save(t_cntl *cntl)
{
	char	*line;

	printf("READY FOR RENDER\n");
	printf("TYPE 'Sample per pixel' FOR ANTIALIASING\n");
	get_next_line(0, &line);
	cntl->scene->global.samples_per_pixel = ft_atoi(line);
	free(line);
	printf("START_RENDER\n");
	render(cntl);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
	printf("FINISH RENDER\n");
}
