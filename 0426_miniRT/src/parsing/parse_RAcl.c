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
    t_camera *tmp_c;

    tmp_c = &(cntl->scene->camera_arr[idx]); 

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
    tmp_c->orig = vec(ft_atoi(tmp[0]), ft_atoi(tmp[1]),ft_atoi(tmp[2]));
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
    tmp_c->normal = vec(ft_atof(tmp[0]), ft_atof(tmp[1]),ft_atof(tmp[2]));
    free(tmp);
    int fov = ft_atoi(one_line[3]);
    tmp_c->viewport_w = 2 * tan(fov/360.0);
	tmp_c->viewport_h = tmp_c->viewport_w / cntl->scene->canvas.aspect_ratio;
	tmp_c->focal_len = 1.0; //고정
	tmp_c->horizontal = vec_mul_num(1, vec_unit(vec_cross(tmp_c->normal, vec(0, 1, 0))));
	tmp_c->vertical = vec_mul_num(1, vec_unit(vec_cross(tmp_c->horizontal, tmp_c->normal)));
	tmp_c->left_bottom = vec_minus(vec_minus(vec_minus(tmp_c->orig, vec_div(2, tmp_c->horizontal)),
								vec_div(2, tmp_c->vertical)), vec(0, 0, 1.0)); //1.0 은 focal len
	
    return (1);
}

int        l_parse(t_cntl *cntl, char **one_line)
{
    char **tmp;
    char **tmp2;

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
    if ((tmp2 = ft_split_char(one_line[3], ',')) == NULL)
    {
        printf("Error: split 오류!\n");
        return (0);
    }
    if (ft_atoi(tmp2[0]) == -1 || ft_atoi(tmp2[1]) == -1 || ft_atoi(tmp2[2]) == -1)
    {
        return (0);
    }
    
    obj_add_back(&cntl->scene->light, object(LIGHT_POINT, light_point(point3(ft_atoi(tmp[0]), ft_atoi(tmp[1]),ft_atoi(tmp[2])), 
                color(ft_atoi(tmp2[0])/255.0, ft_atoi(tmp2[1])/255.0,ft_atoi(tmp2[2])/255.0), ft_atof(one_line[2])), color(0, 0, 0)));

    free(tmp);
    free(tmp2);

    return (1);
}