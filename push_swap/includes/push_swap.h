/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:08:34 by najlee            #+#    #+#             */
/*   Updated: 2021/05/29 23:10:45 by najlee           ###   ########.fr       */
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

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list {
	int				data;
	int				flag;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_stack {
	int				size;
	struct s_list	*head;
	struct s_list	*tail;
}					t_stack;

typedef struct		s_info {
	t_stack			*stack[2];
	t_stack			cmd;
}					t_info;

typedef struct		s_box {
	long long		*arr;
	int				min;
	int				max;
	int				pivot1;
	int				pivot2;
}					t_box;

typedef struct		s_idx {
	int				ra;
	int				rb;
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				tmp;
}					t_idx;

/*
** list.c
*/
t_list				*node(int value, t_list *prev, t_list *next);
int					init_list(t_info *info);
int					*find_pivot(t_info *info, int num, int r);
void				push_all(t_stack *stack, long long arr[], int len);
void				push_head(int value, t_stack *stack);
void				push_tail(int value, t_stack *stack);
void				pop_head(t_stack *stack);
void				pop_tail(t_stack *stack);

/*
** cmd.c
*/
void				sab(t_info *info, int num);
void				ss(t_info *info);
void				pab(t_info *info, int num);
void				rab(t_info *info, int num);
void				rr(t_info *info);
void				rrab(t_info *info, int num);
void				rrr(t_info *info);

/*
** libft.c
*/
long long			ft_atoi(char *str);
void				*ft_memset(void *s, int c, size_t n);
int					check_sorted_a(t_info *info, int r);
int					max(int a, int b);
int					min(int a, int b);

/*
** error_check.c
*/
int					argv_check(long long arr[], int num);
int					print_error();

/*
** quick_sort.c
*/
void				quicksort(int arr[], int left, int right);

/*
** sort.c
*/
void				a_to_b(t_info *info, int r);
void				b_to_a(t_info *info, int r);
void				sort_a(t_info *info, int r);
void				sort_aa(int a, int b, int c, t_info *info);
void				sort_b(t_info *info, int r);
void				sort_bb(int a, int b, int c, t_info *info);
void				sort_3a(t_info *info);
void				sort_33a(int a, int b, int c, t_info *info);
void				sort_3b(t_info *info);
void				sort_33b(int a, int b, int c, t_info *info);

/*
** free.c
*/
void				free_box(t_box *box);
void				free_info(t_info *info);
void				free_stack(t_stack *stack);
void				free_two_list(t_info *info);
void				free_cmd(t_info *info);
int					free_info_box(t_info *info, t_box *box);
void				final_free(t_info *info, t_box *box);
void				free_3_list(t_list *list1, t_list *list2, t_list *list3);
void				free_2_list(t_list *list1, t_list *list2);

void				push_tail_ra(t_info *info);
void				push_tail_rb(t_info *info);
void				push_tail_sa(t_info *info);
void				push_tail_sb(t_info *info);
void				push_tail_pa(t_info *info);
void				push_tail_pb(t_info *info);
void				push_tail_rra(t_info *info);
void				push_tail_rrb(t_info *info);

int					init_cmd(t_info *info);
void				cmd_zip(t_list *now);
void				print_cmd_2(int cmd);
int					fill_arr(int argc, char **argv, t_box *box, t_info *info);
void				free_2_stack(t_stack *stack1, t_stack *stack2);
void				init_idx(t_idx *idx);
void				classification_a(t_info *info, int r,
					int pivot[], t_idx *idx);
void				optimization_a(t_idx *idx, t_info *info);
void				classification_b(t_info *info, int r, int pivot[],
					t_idx *idx);
void				optimization_b(t_idx *idx, t_info *info);
#endif
