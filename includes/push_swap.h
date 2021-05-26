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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // write, close

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

// list.c
t_list	*node(int value, t_list *prev, t_list *next);
void	init_list(t_info *info);
void	push_all(t_stack *stack, int arr[], int len);
void	push_head(int value, t_stack *stack);
void	push_tail(int value, t_stack *stack);
void	pop_head(t_stack *stack);
void	pop_tail(t_stack *stack);

// cmd.c
void	sab(t_info *info, int num);
void	ss(t_info *info);
void	pab(t_info *info, int num);
void	rab(t_info *info, int num);
void	rr(t_info *info);
void	rrab(t_info *info, int num);
void	rrr(t_info *info);

// libft.c
int		ft_atoi(char *str);

// error_check.c
int		argv_check(int arr[], int num);
int		print_error(char *str);

#endif
