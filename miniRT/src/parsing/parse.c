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

int		parsing(t_cntl *cntl, char *rtname)
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

void	parse_num2(char **ol, t_cntl *cntl, int check[])
{
	if (ol[0][0] == 'R')
		check[0]++;
	else if (ol[0][0] == 'A')
		check[1]++;
	else if (ol[0][0] == 'c')
		cntl->scene->c_num++;
}

int		check_parse_num(t_cntl *cntl, char **line)
{
	int		i;
	char	**ol;
	int		ck[5];

	i = -1;
	ft_memset(ck, 0, 5 * sizeof(int));
	while (++i < cmdlen(line))
	{
		if ((ol = ft_split_whitespace(line[i])) == NULL)
			free_print_error(ol, "Error : white_space split이 잘못 됬습니다.\n");
		if ((!s_ncmp(ol[0], "sp", 2)) || (!s_ncmp(ol[0], "pl", 2)) ||
		(!s_ncmp(ol[0], "sq", 2)) || (!s_ncmp(ol[0], "cy", 2)) ||
		(!s_ncmp(ol[0], "tr", 2)) || ol[0][0] == 'l' || ol[0][0] == '#')
			;
		else if (ol[0][0] == 'R' || (ol[0][0] == 'A') || (ol[0][0] == 'c'))
			parse_num2(ol, cntl, ck);
		else
			free_print_error(ol, "Error : 존재하지 않는 단어 입니다!\n");
		ft_freeall(ol);
	}
	if ((ck[0] != 1 || ck[1] != 1 || cntl->scene->c_num == 0) ||
	(!(cntl->scene->c_arr = (t_cam *)malloc(cntl->scene->c_num *
													sizeof(t_cam)))))
		return (print_error("Error : camera 할당 || RAc개수 오류\n"));
	return (parsing_all(cntl, line, cmdlen(line)));
}
