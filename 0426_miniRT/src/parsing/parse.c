#include "../../includes/minirt.h"

int	cal_cmd_len(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int		parsing(t_cntl *cntl, char *rtname)
{
	int		fd;
	char	line[BUFFER_SIZE];
	char	**tmp;
	int		read_len;

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

	if (parsing_all(&cntl, tmp) == 0)
	{
		printf("Error : parsing_all error\n");
		return (0);
	}

	free(tmp);
	return (1);
}

 int parsing_all(t_cntl *cntl, char **line)
{
	int i;
	int cmd_len;
	char **one_line;

	i = 0;
	cmd_len = cal_cmd_len(line);
	while (i < cmd_len)
	{
		if ((one_line = ft_split_whitespace(line[i])) == NULL)
			return (0);
		if (one_line[0] == 'R')
			if (R_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0] == 'A')
			if (A_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0] == 'c')
			if (c_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0] == 'l')
			if (l_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0][0] == 's' && one_line[0][1] == 'p')
			if (sp_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0][0] == 'p' && one_line[0][1] == 'l')
			if (pl_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0][0] == 's' && one_line[0][1] == 'q')
			if (sq_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0][0] == 'c' && one_line[0][1] == 'y')
			if (cy_parse(&cntl, one_line) == 0)
				return (0);
		else if (one_line[0][0] == 't' && one_line[0][1] == 'r')
			if (tr_parse(&cntl, one_line) == 0)
				return (0);
		else
		{
			printf("Error : 존재하지 않는 단어(?) 입니다!\n");
			return (0);
		}
		free(one_line);
		i++;
	}
	return (1);
}