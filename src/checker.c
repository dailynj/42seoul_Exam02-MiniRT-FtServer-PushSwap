#include "../includes/push_swap.h"

int	do_instruction_2(t_info *info, char line[])
{
	if(line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rab(info, A);
	else if(line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rab(info, B);
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(info);
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rrab(info, A);
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		rrab(info, B);
	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		rrr(info);
	else
		return (0);
	return (1);
}

int	do_instruction(t_info *info)
{
	int		ret;
	char	line[5];

	if ((ret = read(0, line, 4)) <= 0)
		return (2);
	if(line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sab(info, A);
	else if(line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sab(info, B);
	else if(line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(info);
	else if(line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pab(info, A);
	else if(line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pab(info, B);
	else
		return (do_instruction_2(info, line));
	return (1);
}

int		checker(int argc, char **argv)
{
	int		idx;
	t_info	*info;
	t_box	*box;
	int		tmp;

	idx = -1;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	if (!(box = (t_box *)malloc(sizeof(t_box))))
	{
		free(info);
		return (0);
	}
	if (init_list(info) == 0)
		return (0);
	if (!(box->arr = malloc(argc * sizeof(long long))))
	{
		free_info(info);
		free_box(box);
		return (0);
	}
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
		{
			free_info(info);
			free_box(box);
			return (print_error());
		}
	}
	push_all(info->stack[A], box->arr, argc - 1);
	while ((tmp = do_instruction(info)) == 1)
		;
	if (tmp == 0)
		return (print_error());
	if (check_sorted_a(info, argc - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	free_two_list(info);
	free_info(info);
	free_cmd(info);
	free(info);
	free_box(box);
	return (0);
}

int		main(int argc, char **argv)
{
	checker(argc, argv);
	return (0);
}