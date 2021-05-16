/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:49:55 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:44:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_cntl	cntl;

	if (argc != 2 && argc != 3)
		return (print_error("Error : Argument Error!\n"));
	
	cntl.mlx = mlx_init();
	if ((cntl.scene = scene_init()) == NULL)
		return (print_error("Error : scene_init 에러!\n"));
	if (parsing(&cntl, argv[1]) == 0)
		return (print_error("Error : Parsing Error!\n"));


	if (argc == 2)
		return (mlx_show_window(&cntl));
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) != 0)
			return (print_error("Error : --save 인수가 잘못되었습니다\n"));
		return (mlx_save_image(&cntl));
	}
	return (0);
}

int	mlx_show_window(t_cntl *cntl)
{
	t_color	pixel_color;
	int			i;
	int			j;
	int			idx;

    cntl->win = mlx_new_window(cntl->mlx, cntl->scene->canvas.width, cntl->scene->canvas.height, "NAJEONG's World!");
	if (!(cntl->image = (t_data *)malloc(cntl->scene->camera_num * sizeof(t_data))))
		print_error("Error : data malloc Fail!!!\n");
	printf("** START SHOW **\n");
	idx = 0;
	while (idx < cntl->scene->camera_num){
		cntl->image[idx].img = mlx_new_image(cntl->mlx, cntl->scene->canvas.width, cntl->scene->canvas.height);
		cntl->image[idx].addr = mlx_get_data_addr(cntl->image[idx].img, &cntl->image[idx].bits_per_pixel, &cntl->image[idx].line_length, &cntl->image[idx].endian);
		j = cntl->scene->canvas.height - 1;
		printf("-> make %dth image\n", idx + 1);
		while (j >= 0)
		{
			i = 0;
			while (i < cntl->scene->canvas.width)
			{
				cntl->scene->ray = ray_primary(&cntl->scene->camera_arr[idx], (double)i / (cntl->scene->canvas.width - 1), (double)j / (cntl->scene->canvas.height - 1));
				pixel_color = ray_color(cntl->scene);
				my_mlx_pixel_put(&cntl->image[idx], i, cntl->scene->canvas.height - 1 - j, write_color(0, pixel_color));
				++i;
			}
			--j;
		}
		idx++;
	}
	
	printf("** FINISH **\n");
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->image[cntl->scene->camera_idx].img, 0, 0);
	mlx_key_hook(cntl->win, key_hook, cntl);  //왜 &cntl은 안됨?
	mlx_loop(cntl->mlx);
	
	return (0);
}

int	mlx_save_image(t_cntl *cntl)
{
	t_color	pixel_color;
	int			i;
	int			j;
	
	printf("** START **\n");
	int height = cntl->scene->canvas.height;
	int width = cntl->scene->canvas.width;
	unsigned char image[height][width][3];
    char* imageFileName = (char*) "BitmapImage.bmp";

	if (!(cntl->image = (t_data *)malloc(sizeof(t_data))))
		print_error("Error : data malloc Fail!!!\n");
	j = cntl->scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < cntl->scene->canvas.width)
		{
			cntl->scene->ray = ray_primary(&cntl->scene->camera_arr[0], (double)i / (cntl->scene->canvas.width - 1), (double)j / (cntl->scene->canvas.height - 1));
			pixel_color = ray_color(cntl->scene);
			image[height - 1 - j][i][2] = pixel_color.x;
			image[height - 1 - j][i][1] = pixel_color.y;
			image[height - 1 - j][i][0] = pixel_color.z;
			++i;
		}
		--j;
	}
	printf("** SAVE BitmapImage.bmp FILE **\n");
	generateBitmapImage((unsigned char*) image, cntl->scene->canvas.height, cntl->scene->canvas.width, imageFileName);
	return (0);
}

void generateBitmapImage (unsigned char* image, int height, int width, char* imageFileName)
{
    int widthInBytes = width * 3;

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(imageFileName, "w+b");

    unsigned char* fileHeader = createBitmapFileHeader(height, stride);
    fwrite(fileHeader, 1, 14, imageFile);

    unsigned char* infoHeader = createBitmapInfoHeader(height, width);
    fwrite(infoHeader, 1, 40, imageFile);

    int i;
    for (i = 0; i < height; i++) {
        fwrite(image + (i*widthInBytes), 3, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}

unsigned char* createBitmapFileHeader (int height, int stride)
{
    int fileSize = 14 + 40 + (stride * height);

    static unsigned char fileHeader[] = {
        // 0,0,     /// signature
        // 0,0,0,0, /// image file size in bytes
        // 0,0,0,0, /// reserved
        // 0,0,0,0, /// start of pixel array
		0x42, 0x4d,
		0x46, 0x00, 0x00, 0x00,
		0x00, 0x00, 
		0x00, 0x00,
		0x36, 0x00, 0x00, 0x00,
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(14 + 40);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader (int height, int width)
{
    static unsigned char infoHeader[] = {
        // 0,0,0,0, /// header size
        // 0,0,0,0, /// image width
        // 0,0,0,0, /// image height
        // 0,0,     /// number of color planes
        // 0,0,     /// bits per pixel
        // 0,0,0,0, /// compression
        // 0,0,0,0, /// image size
        // 0,0,0,0, /// horizontal resolution
        // 0,0,0,0, /// vertical resolution
        // 0,0,0,0, /// colors in color table
        // 0,0,0,0,
		0x28, 0x00, 0x00, 0x00,
		0x02, 0x00, 0x00, 0x00,
		0x02, 0x00, 0x00, 0x00,
		0x01, 0x00,
		0x18, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x10, 0x00, 0x00, 0x00,
		0x13, 0x0b, 0x00, 0x00,
		0x13, 0x0b, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xff,
		0xff, 0xff, 0xff,
		0x00, 0x00,
		0xff, 0x00, 0x00,
		0x00, 0xff, 0x00,
		0x00, 0x00,
    };
	

    infoHeader[ 0] = (unsigned char)(40);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(3*8);

    return infoHeader;
}