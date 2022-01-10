/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:18:27 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/06 20:32:57 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h> // delete

typedef struct s_stack
{
	int	content;
	struct s_stack *next;
	struct s_stack *prev;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}					t_stack;

typedef struct s_handle
{
	unsigned int	size;
	t_stack			*a;
	t_stack			*b;
	int				len_a;
	int				len_b;
	int				max_value;
	int				max_score;
}					t_handle;

// operations with stacks
void		ft_sa(t_handle *handle);
void		ft_sb(t_handle *handle);
void		ft_ss(t_handle *handle);
int			push_front(t_stack **stack_a, int content);
void		pop_front(t_handle *handle, char which_stack);
void		ft_pa(t_handle *handle);
void		ft_pb(t_handle *handle);
void		ft_ra(t_handle *handle);
void		ft_rb(t_handle *handle);
void		ft_rr(t_handle *handle);
void		ft_rra(t_handle *handle);
void		ft_rrb(t_handle *handle);
void		ft_rrr(t_handle *handle);
t_handle	*init_stack(int *numbers, int len);
void		print_state(t_handle *handle);
void		push_swap(t_handle *handle, int *nums);
void		do_rotate(t_handle *handle, t_stack *node);
void		do_rev_rotate(t_handle *handle, t_stack *node);
void		rra_and_rb(t_handle *handle, t_stack *node);
void		rrb_and_ra(t_handle *handle, t_stack *node);
void		find_start(t_handle *handle);
int			index_a(t_handle *handle, int num);
void		triple_sort(t_handle *handle, int *nums); /* -> parsing.c */
void		free_lists(t_handle *handle);

// parsing arguments
int			validate_numbers(char **av, int len);
int			is_repetition(int *args, int len);
int			*str_to_num(char **argv, int len, int is_splitted);
int			overflow(char **argv, int len);
int			display_error(int i, int **args);
void		free_argv(char **argv, int len);

//regular functions
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
int			max(int a, int b);
int			min4(int a, int b, int c, int d);
int			min2(int a, int b);
char		**ft_split(char *s, char c, int *argc);

#endif