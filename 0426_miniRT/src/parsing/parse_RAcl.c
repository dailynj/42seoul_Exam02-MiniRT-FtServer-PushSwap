#include "../../includes/minirt.h"

int        R_parse(t_cntl *cntl, char **one_line)
{
    if (cal_cmd_len(one_line) != 3)
    {
        printf("Error: R 인수 개수 오류\n");
        return (0);
    }
    cntl->scene->canvas.width = ft_atoi(one_line[1]);
    cntl->scene->canvas.height = ft_atoi(one_line[2]);
    cntl->scene->canvas.aspect_ratio = (double)ft_atoi(one_line[1]) / ft_atoi(one_line[2]);

    return (1);
}

int        A_parse(t_cntl *cntl, char **one_line)
{
    char **amb;
    double ratio;
    
    if (cal_cmd_len(one_line) != 3)
    {
        printf("Error: A 인수 개수 오류\n");
        return (0);
    }
    if ((amb = ft_split_char(one_line[2], ',')) == NULL)
    {
        printf("Error: split 오류!\n");
        return (0);
    }
    ratio = ft_atof(one_line[1]);
    if (ft_atoi(amb[0]) == -1 || ft_atoi(amb[1]) == -1 || ft_atoi(amb[2]) == -1)
    {
        printf("Error: atoi error!\n");
        return (0);
    }
    cntl->scene->ambient = color(ratio * ft_atoi(amb[0]),
            ratio * ft_atoi(amb[1]), ratio * ft_atoi(amb[2]));

    free(amb);
    return (1);
}

int        c_parse(t_cntl *cntl, char **one_line, int idx)
{
    char **tmp;

    if (cal_cmd_len(one_line) != 4)
    {
        printf("Error: camera 인수 개수 오류\n");
        return (0);
    }
    if ((tmp = ft_split_char(one_line[1], ',')) == NULL)
    {
        printf("Error: split 오류!\n");
        return (0);
    }
    if (ft_atoi(tmp[0]) == -1 || ft_atoi(tmp[1]) == -1 || ft_atoi(tmp[2]) == -1)
    {
        return (0);
    }
    cntl->scene->camera_arr[idx].orig = vec(ft_atoi(tmp[0]), ft_atoi(tmp[1]),ft_atoi(tmp[2]));
    free(tmp);
    if ((tmp = ft_split_char(one_line[2], ',')) == NULL)
    {
        printf("Error: split 오류!\n");
        return (0);
    }
    if (ft_atof(tmp[0]) == -1 || ft_atof(tmp[1]) == -1 || ft_atof(tmp[2]) == -1)
    {
        printf("Error: atoi error!\n");
        return (0);
    }
    cntl->scene->camera_arr[idx].normal = vec(ft_atof(tmp[0]), ft_atof(tmp[1]),ft_atof(tmp[2]));
    free(tmp);
    int fov = ft_atoi(one_line[3]);
    cntl->scene->camera_arr[idx].viewport_w = 2 * tan(fov/360.0);
	cntl->scene->camera_arr[idx].viewport_h = cntl->scene->camera_arr[idx].viewport_w / cntl->scene->canvas.aspect_ratio;
	cntl->scene->camera_arr[idx].focal_len = 1.0; //고정
	cntl->scene->camera_arr[idx].horizontal = vec_mul_num(1, vec_unit(vec_cross(cntl->scene->camera_arr[idx].normal, vec(0, 1, 0))));
	cntl->scene->camera_arr[idx].vertical = vec_mul_num(1, vec_unit(vec_cross(cntl->scene->camera_arr[idx].horizontal, cntl->scene->camera_arr[idx].normal)));
	cntl->scene->camera_arr[idx].left_bottom = vec_minus(vec_minus(vec_minus(cntl->scene->camera_arr[idx].orig, vec_div(2, cntl->scene->camera_arr[idx].horizontal)),
								vec_div(2, cntl->scene->camera_arr[idx].vertical)), vec(0, 0, 1.0)); //1.0 은 focal len
	
    return (1);
}

int        l_parse(t_cntl *cntl, char **one_line)
{
    cntl = 0;
    one_line = 0;

    return (1);
}