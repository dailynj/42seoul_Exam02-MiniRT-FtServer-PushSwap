#include "../includes/push_swap.h"

void	A_to_B(t_info *info, int r)
{
	int ra_;
	int pb_;
	int rb_;
	int i;
	int *pivot;

	ra_ = 0;
	pb_ = 0;
	rb_ = 0;
	i = -1;
	pivot = find_pivot(info, A, r);
	if (r <= 3)
		return (sort_a(info, r));
	while (r--)
	{
		if (info->stack[A]->head->next->data >= pivot[1])
		{
			rab(info, A);
			ra_++;
		}
		else
		{
			pab(info, B);
			pb_++;
			if (info->stack[B]->head->next->data >= pivot[0])
			{
				rab(info, B);
				rb_++;
			}
		}
	}
	// rrr 로 합칠 수 있음
	while(++i < ra_)
		rrab(info, A);
	while(++i < ra_ + rb_)
		rrab(info, B);
	A_to_B(info, ra_);
	B_to_A(info, rb_);
	B_to_A(info, pb_ - ra_);
}

void	B_to_A(t_info * info, int r)
{
	int rb_;
	int pa_;
	int ra_;
	int	i;
	int	*pivot;

	rb_ = 0;
	pa_ = 0;
	ra_ = 0;
	i = -1;
	if (r < 3)
		return (sort_b(info, r));
	pivot = find_pivot(info, B, r);
	while (r--)
	{
		if (info->stack[B]->head->next->data < pivot[0])
		{
			rab(info, B);
			rb_++;
		}	
		else
		{
			pab(info, A);
			pa_++;
			if (info->stack[B]->head->next->data >= pivot[1])
				rab(info, A);
				ra_++;
		}
	}
	A_to_B(info, pa_ - ra_);
	// rrr 로 합칠 수 있음
	while(++i < ra_)
		rrab(info, A);
	while(++i < ra_ + rb_)
		rrab(info, B);
	A_to_B(info, rb_);
	B_to_A(info, ra_);
}