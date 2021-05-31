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
		push_tail(RA, &info->cmd);
		rab(info, A);
		push_tail(SA, &info->cmd);
		sab(info, A);
		push_tail(RRA, &info->cmd);
		rrab(info, A);
	}
	else if (b < c && c < a)
	{
		push_tail(RA, &info->cmd);
		rab(info, A);
	}
	else
		sort_33a(a, b, c, info);
}

void	sort_33a(int a, int b, int c, t_info *info)
{
	if (b < a && a < c)
	{
		push_tail(SA, &info->cmd);
		sab(info, A);
	}
	else if (c < a && a < b)
	{
		push_tail(RRA, &info->cmd);
		rrab(info, A);
	}
	else if (c < b && b < a)
	{
		push_tail(SA, &info->cmd);
		sab(info, A);
		push_tail(RRA, &info->cmd);
		rrab(info, A);
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
			push_tail(RRB, &info->cmd);
			rrab(info, B);
		}
		else if (c < a && a < b)
		{
			push_tail(SB, &info->cmd);
			sab(info, B);
		}
		else
		{
			sort_33b(a, b, c, info);
		}
		push_tail(PA, &info->cmd);
		push_tail(PA, &info->cmd);
		push_tail(PA, &info->cmd);
		pab(info, A);
		pab(info, A);
		pab(info, A);
}

void	sort_33b(int a, int b, int c, t_info *info)
{
	if (a < b && b < c)
	{
		push_tail(SB, &info->cmd);
		sab(info, B);
		push_tail(RRB, &info->cmd);
		rrab(info, B);
	}
	else if (a < c && c < b)
	{	
		push_tail(RB, &info->cmd);
		rab(info, B);
	}
	else if (b < c && c < a)
	{
		push_tail(RB, &info->cmd);
		rab(info, B);
		push_tail(SB, &info->cmd);
		sab(info, B);
		push_tail(RRB, &info->cmd);
		rrab(info, B);
	}
}