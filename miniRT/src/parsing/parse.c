/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 21:46:22 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	parsing(t_cntl *cntl, char *rtname)
{
	int		fd;
	char	line[BUFFER_SIZE];
	char	**tmp;
	int		read_len;

	if (check_rt(rtname) == FALSE)
		return (0);
	fd = open(rtname, O_RDONLY);
	if (fd == -1)
		return (print_error("Error : open 에러입니다!\n"));
	read_len = read(fd, line, BUFFER_SIZE);
	if (read_len == 0)
		return (print_error("Error : read_len 에러\n"));
	if ((tmp = ft_split_char(line, '\n')) == NULL){
		ft_freeall(tmp);
		return (print_error("Error : split 에러입니다!\n"));
	}
	if (check_parse_num(cntl, tmp) == 0)
		return (print_error("Error : parsing_all error\n"));
	ft_freeall(tmp);
	return (1);
}

int	check_parse_num(t_cntl *cntl, char **line)
{
	int		i;
	int		cmd_len;
	char	**one_line;
	int		check[5];

	i = 0;
	ft_memset(check, 0, 5 * sizeof(int));
	cmd_len = cal_cmd_len(line);
	while (i < cmd_len)
	{
		if ((one_line = ft_split_whitespace(line[i])) == NULL){
			ft_freeall(one_line);
			return (print_error("Error : white_space split이 잘못 됬습니다.\n"));
		}
		if ((one_line[0][0] == 's' && one_line[0][1] == 'p') || (one_line[0][0] 
			== 'p' && one_line[0][1] == 'l') || (one_line[0][0] == 's' && 
			one_line[0][1] == 'q') || (one_line[0][0] == 'c' && one_line[0][1] 
			== 'y') || (one_line[0][0] == 't' && one_line[0][1] == 'r')
			|| one_line[0][0] == 'l' || one_line[0][0] == '#')
			;
		else if (one_line[0][0] == 'R')
			check[0]++;
		else if (one_line[0][0] == 'A')
			check[1]++;
		else if (one_line[0][0] == 'c')
			cntl->scene->camera_num++;
		else
		{
			ft_freeall(one_line);
			return (print_error("Error : 존재하지 않는 단어(?) 입니다!\n"));
		}
		ft_freeall(one_line);
		i++;
	}
	
	if (check[0] != 1 || check[1] != 1 || cntl->scene->camera_num == 0)
		return (print_error("Error : R이나 A이나 c의 개수가 틀립니다!\n"));
	if (!(cntl->scene->camera_arr = (t_camera *)malloc(cntl->scene->camera_num * sizeof(t_camera))))
		return (print_error("Error : camera 할당이 제대로 되지 않았습니다\n"));
	return(parsing_all(cntl, line, cmd_len));
	return (1);
}

int	parsing_all(t_cntl *cntl, char **line, int cmd_len)
{
	int		i;
	char	**one_line;

	int _cam = 0;
	i = 0;
	while (i < cmd_len)
	{
		if ((one_line = ft_split_whitespace(line[i])) == NULL)
			return (0);
		if (one_line[0][0] == 's' && one_line[0][1] == 'p')
		{
			if (sp_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'p' && one_line[0][1] == 'l')
		{
			if (pl_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 's' && one_line[0][1] == 'q')
		{
			if (sq_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'c' && one_line[0][1] == 'y')
		{
			if (cy_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 't' && one_line[0][1] == 'r')
		{
			if (tr_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'R')
		{
			if (r_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'A')
		{
			if (a_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'c')
		{
			
			if (c_parse(cntl, one_line, _cam) == 0)
			{
				return (0);
			}
			_cam++;
		}
		else if (one_line[0][0] == 'l')
		{
			if (l_parse(cntl, one_line) == 0)
				return (0);
		}
		ft_freeall(one_line);
		i++;
	}
	return (1);
}
