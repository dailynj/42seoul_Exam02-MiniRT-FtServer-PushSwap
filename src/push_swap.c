#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	init_list(info);
	printf("%d", info->stack[0]->size);
	return (0);
}