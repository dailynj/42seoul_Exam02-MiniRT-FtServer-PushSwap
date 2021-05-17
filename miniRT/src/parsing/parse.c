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
	if ((tmp = ft_split_char(line, '\n')) == NULL)
	{
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
	char	**ol;
	int		check[5];

	i = -1;
	ft_memset(check, 0, 5 * sizeof(int));
	while (++i < cmdlen(line))
	{
		if ((ol = ft_split_whitespace(line[i])) == NULL)
			free_print_error(ol, "Error : white_space split이 잘못 됬습니다.\n");
		if ((ol[0][0] == 's' && ol[0][1] == 'p') || (ol[0][0] == 'p' &&
		ol[0][1] == 'l') || (ol[0][0] == 's' && ol[0][1] == 'q') ||
		(ol[0][0] == 'c' && ol[0][1] == 'y') || (ol[0][0] == 't'
		&& ol[0][1] == 'r') || ol[0][0] == 'l' || ol[0][0] == '#')
			;
		else if (ol[0][0] == 'R')
			check[0]++;
		else if (ol[0][0] == 'A')
			check[1]++;
		else if (ol[0][0] == 'c')
			cntl->scene->c_num++;
		else
			free_print_error(ol, "Error : 존재하지 않는 단어 입니다!\n");
		ft_freeall(ol);
	}
	if ((check[0] != 1 || check[1] != 1 || cntl->scene->c_num == 0) ||
	(!(cntl->scene->c_arr = (t_cam *)malloc(cntl->scene->c_num * sizeof(t_cam)))))
		return (print_error("Error : camera 할당 || RAc개수 오류\n"));
	return (parsing_all(cntl, line, cmdlen(line)));
	return (1);
}

int	free_print_error(char **ol, char *str)
{
	ft_freeall(ol);
	return (print_error(str));
}

int	parsing_all(t_cntl *cntl, char **line, int cmd_len)
{
	int		i;
	char	**ol;
	int		cam_t;

	cam_t = 0;
	i = 0;
	while (i < cmd_len)
	{
		if ((ol = ft_split_whitespace(line[i])) == NULL)
			return (0);
		if ((ol[0][0] == 's' && ol[0][1] == 'p') || (ol[0][0] == 'p' && ol[0][1] == 'l')
			|| (ol[0][0] == 's' && ol[0][1] == 'q') || (ol[0][0] == 'c' && ol[0][1] == 'y')
			|| (ol[0][0] == 't' && ol[0][1] == 'r'))
		{
			if (parse_object(cntl, ol) == 0)
				return (0);
		}
		else if (ol[0][0] == 'R')
		{
			if (r_parse(cntl, ol) == 0)
				return (0);
		}
		else if (ol[0][0] == 'A')
		{
			if (a_parse(cntl, ol) == 0)
				return (0);
		}
		else if (ol[0][0] == 'c')
		{
			if (c_parse(cntl, ol, cam_t) == 0)
				return (0);
			cam_t++;
		}
		else if (ol[0][0] == 'l')
		{
			if (l_parse(cntl, ol) == 0)
				return (0);
		}
		ft_freeall(ol);
		i++;
	}
	return (1);
}

int	parse_object(t_cntl *cntl, char **ol)
{
	if (ol[0][0] == 's' && ol[0][1] == 'p')
	{
		if (sp_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 'p' && ol[0][1] == 'l')
	{
		if (pl_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 's' && ol[0][1] == 'q')
	{
		if (sq_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 'c' && ol[0][1] == 'y')
	{
		if (cy_parse(cntl, ol) == 0)
			return (0);
	}
	else if (ol[0][0] == 't' && ol[0][1] == 'r')
		if (tr_parse(cntl, ol) == 0)
			return (0);
	return (1);
}