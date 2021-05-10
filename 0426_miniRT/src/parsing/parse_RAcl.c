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
    return (1);
}

int        A_parse(t_cntl *cntl, char **one_line)
{
    char **amb;
    char ratio;

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
    
    ratio = ft_atoi(one_line[1]);
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

int        c_parse(t_cntl *cntl, char **one_line)
{
    cntl = 0;
    one_line = 0;

    return (1);
}

int        l_parse(t_cntl *cntl, char **one_line)
{
    cntl = 0;
    one_line = 0;

    return (1);
}