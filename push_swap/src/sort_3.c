#include "../includes/push_swap.h"

void	sort_3a(t_info *info)
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
		sort_33a(a, b, c, info);
}

void	sort_33a(int a, int b, int c, t_info *info)
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

void	sort_3b(t_info *info)
{
	int a;
	int b;
	int c;

	a = info->stack[B]->head->next->data;
	b = info->stack[B]->head->next->next->data;
	c = info->stack[B]->head->next->next->next->data;
	if (b < a && a < c)
		{
			rrab(info, B, 1);
		}
		else if (c < a && a < b)
		{
			sab(info, B, 1);
		}
		else
		{
			sort_33b(a, b, c, info);
		}
		pab(info, A);
		pab(info, A);
		pab(info, A);
}

void	sort_33b(int a, int b, int c, t_info *info)
{
	if (a < b && b < c)
	{
		sab(info, B, 1);
		rrab(info, B, 1);
	}
	else if (a < c && c < b)
	{
		rab(info, B, 1);
	}
	else if (b < c && c < a)
	{
		rab(info, B, 1);
		sab(info, B, 1);
		rrab(info, B, 1);
	}
}