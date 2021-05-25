#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1

typedef struct	s_list {
    int				data;
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
	t_stack		cmd;
}				t_info;

// list.c
void init_list(t_info *info);
t_list *node(int value, t_list *prev, t_list *next);
void push_head(int value, t_stack *stack);
void push_tail(int value, t_stack *stack);
void pop_head(t_stack *stack);
void pop_tail(t_stack *stack);

// cmd.c
void sab(t_stack *stack);
void ss(t_stack **stack);
void pab(t_stack **stack, int n);
void rab(t_stack *stack);
void rr(t_stack **stack);
void rrab(t_stack *stack);
void rrr(t_stack **stack);

#endif