#include "../includes/push_swap.h"

int	do_instruction(t_info *info)
{
	int		ret;
	char	line[5];

	// ft_bzero(line, 4); 
	// if (line[0] == EOF)
	// 	return (2);
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
	else if(line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
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

int		check_sorted(t_info *info, int r)
{
	int		tmp_arr[r];
	t_list	*now;
	int		i;

	i = -1;
	if (info->stack[A]->size != r)
		return (0);
	now = info->stack[A]->head->next;
	while (++i < r && now->flag)
	{
		tmp_arr[i] = now->data;
		now = now->next;
	}
	quicksort(tmp_arr, 0, r - 1);
	i = -1;
	now = info->stack[A]->head->next;
	while (++i < r && now->flag)
	{
		if (tmp_arr[i] != now->data)
			return (0);
		now = now->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		idx;
	t_info	*info;
	t_box	*box;

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
		free(info);
		free_box(box);
		return (0);
	}
	while (++idx < argc - 1)
	{
		box->arr[idx] = ft_atoi(argv[idx + 1]);
		if ((box->arr[idx] == 0 && argv[idx + 1][0] != '0')
			|| argv_check(box->arr, idx) == 0)
			return (print_error("Error\n"));
	}
	push_all(info->stack[A], box->arr, argc - 1);
	int tmp;
	while ((tmp = do_instruction(info)) == 1)
		;
	if (tmp == 0)
		return (print_error("Error!\n"));
	if (check_sorted(info, argc - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(info); // 전부 free 해야됨
	free(box);
	return (0);
}
