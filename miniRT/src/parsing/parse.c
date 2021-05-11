/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:52:09 by najlee            #+#    #+#             */
/*   Updated: 2021/05/12 00:52:10 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		parsing(t_cntl *cntl, char *rtname)
{
	int		fd;
	char	line[BUFFER_SIZE];
	char	**tmp;
	int		read_len;

	if (check_rt(rtname) == FALSE) // 파일이 .rt로 끝나는것 확인
		return (0);

	fd = open(rtname, O_RDONLY);
	if (fd == -1)
	{
		printf("Error : open 에러입니다!\n");
		return (0);
	}
	
	read_len = read(fd, line, BUFFER_SIZE);

	if (read_len == 0)
	{
		printf("Error : read_len 에러\n");
		return (0);
	}
	if ((tmp = ft_split_char(line, '\n')) == NULL)
	{
		printf("Error : split 에러입니다!\n");
		return (0);
	}
	if (check_parse_num(cntl, tmp) == 0)
	{
		printf("Error : parsing_all error\n");
		return (0);
	}

	free(tmp);
	return (1);
}

int check_parse_num(t_cntl *cntl, char **line)
{
	int i;
	int cmd_len;
	char **one_line;
	int	check[10];

	i = 0;
	ft_memset(check, 0, 10);
	cmd_len = cal_cmd_len(line);
	while (i < cmd_len)
	{
		if ((one_line = ft_split_whitespace(line[i])) == NULL)
			return (0);
		if (one_line[0][0] == 'R')
			check[0]++;
		else if (one_line[0][0] == 'A')
			check[1]++;
		else if (one_line[0][0] == 'c')
			check[2]++;
		else if (one_line[0][0] == 'l')
			check[3]++;
		else if (one_line[0][0] == 's' && one_line[0][1] == 'p')
			check[4]++;
		else if (one_line[0][0] == 'p' && one_line[0][1] == 'l')
			check[5]++;
		else if (one_line[0][0] == 's' && one_line[0][1] == 'q')
			check[6]++;
		else if (one_line[0][0] == 'c' && one_line[0][1] == 'y')
			check[7]++;
		else if (one_line[0][0] == 't' && one_line[0][1] == 'r')
			check[8]++;
		else if (one_line[0][0] == '#')
			;
		else
		{
			printf("Error : 존재하지 않는 단어(?) 입니다!\n");
			return (0);
		}
		free(one_line);
		i++;
	}
	if (check[0] != 1 || check[1] != 1 || check[2] == 0)
	{
		printf("Error : R이나 A이나 c의 개수가 틀립니다!\n");
		return (0);
	}
	if (!(cntl->scene->camera_arr = (t_camera *)malloc(check[2] * sizeof(t_camera))))
		return (0);
	
	parsing_all(cntl, line, cmd_len);
	return (1);
}

int parsing_all(t_cntl *cntl, char **line, int cmd_len)
{
	int i;
	int _cam = 0;
	char **one_line;

	i = 0;
	while (i < cmd_len)
	{
		
		if ((one_line = ft_split_whitespace(line[i])) == NULL)
			return (0);
		if (one_line[0][0] == 's' && one_line[0][1] == 'p'){
			if (sp_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'p' && one_line[0][1] == 'l'){
			if (pl_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 's' && one_line[0][1] == 'q'){
			if (sq_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'c' && one_line[0][1] == 'y'){
			if (cy_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 't' && one_line[0][1] == 'r'){
			if (tr_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'R'){
			if (R_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'A'){
			if (A_parse(cntl, one_line) == 0)
				return (0);
		}
		else if (one_line[0][0] == 'c'){
			if (c_parse(cntl, one_line, _cam) == 0){
				return (0);
			}
			_cam++;
		}
		else if (one_line[0][0] == 'l'){
			if (l_parse(cntl, one_line) == 0)
				return (0);
		}
		free(one_line);
		i++;
	}
	return (1);
}
