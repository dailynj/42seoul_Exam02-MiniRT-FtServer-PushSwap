/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:08:34 by najlee            #+#    #+#             */
/*   Updated: 2021/05/25 22:08:35 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> // write, close

# define max(a, b) (((a) < (b)) ? (b) : (a))
# define min(a, b) (((a) > (b)) ? (b) : (a))

typedef struct	s_list {
    int				data;
	int				flag;
    struct s_list*	next;
    struct s_list*	prev;
}				t_list;

typedef struct	s_stack {
	int				size;
	struct s_list*	head;
	struct s_list*	tail;
}				t_stack;

typedef struct	s_info {
	t_stack		*stack[2];
	// t_stack		cmd;
}				t_info;

typedef struct	s_box {
	long long	*arr;
	int			min;
	int			max;
	int			pivot1;
	int			pivot2;
}				t_box;

// list.c
t_list		*node(int value, t_list *prev, t_list *next);
void		init_list(t_info *info);
int			*find_pivot(t_info *info, int num, int r);
void		push_all(t_stack *stack, long long arr[], int len);
void		push_head(int value, t_stack *stack);
void		push_tail(int value, t_stack *stack);
void		pop_head(t_stack *stack);
void		pop_tail(t_stack *stack);

// cmd.c
void		sab(t_info *info, int num, int flag);
void		ss(t_info *info);
void		pab(t_info *info, int num);
void		rab(t_info *info, int num, int flag);
void		rr(t_info *info);
void		rrab(t_info *info, int num, int flag);
void		rrr(t_info *info);

// libft.c
long long	ft_atoi(char *str);
void		*ft_memset(void *s, int c, size_t n);

// error_check.c
int			argv_check(long long arr[], int num);
int			print_error(char *str);

// quick_sort.c
void		quicksort(int arr[], int left, int right);

// sort.c
void		a_to_b(t_info *info, int r);
void		b_to_a(t_info * info, int r);
void		sort_a(t_info* info, int r);
void		sort_aa(int a, int b, int c, t_info *info);
void		sort_b(t_info* info, int r);
void		sort_bb(int a, int b, int c, t_info *info);
void		sort_3a(t_info *info);
void		sort_33a(int a, int b, int c, t_info *info);
void		sort_3b(t_info *info);
void		sort_33b(int a, int b, int c, t_info *info);

#endif
