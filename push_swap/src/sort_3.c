#include "../includes/push_swap.h"

void	sort_3(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->stack[A]->head->next->data;
	b = info->stack[A]->head->next->next->data;
	c = info->stack[A]->head->next->next->next->data;
	if (a < c && c < b)
	{
		rab(info, A, 1);
		sab(info, A, 1);
		rrab(info, A, 1);
	}
	else if (b < c && c < a)
	{
		rab(info, A, 1);
	}
	else
		sort_33(a, b, c, info);
}

void	sort_33(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
		sab(info, A, 1);
	else if (c < a && a < b)
	{
		rrab(info, A, 1);
	}
	else if (c < b && b < a)
	{
		sab(info, A, 1);
		rrab(info, A, 1);
	}
}