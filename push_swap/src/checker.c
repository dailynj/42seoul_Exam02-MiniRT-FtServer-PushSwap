#include "../includes/push_swap.h"

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
	if (check_sorted_a(info, argc - 1))
		return (0);
	a_to_b(info, argc - 1);
	free_info(info); // 모두 free 해야됨
	free_box(box);
	print_cmd(&info->cmd);
	// while(1)
	// 	;
	return (0);
}
