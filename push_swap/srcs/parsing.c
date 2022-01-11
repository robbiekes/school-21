/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:41:39 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/11 20:14:40 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(void *args, int exit_code, int is_free) // проверить подключен ли хедер для exit
{
	if (exit_code)
		write(2, "Error\n", 6);
	if (is_free)
		free(args);
	exit(exit_code);
}

int	almost_sorted(t_handle *handle)
{
	t_stack	*tmp;
	int		flag;

	tmp = handle->a;
	flag = 0;
	while (tmp)
	{
		if (tmp->content < tmp->prev->content)
		{
			if (flag)
				return (0);
			flag = 1;
		}
		tmp = tmp->next;
	}
	return (1);
}

void print_state(t_handle *handle) // dont forget to delete this stuff
{
	int a = handle->len_a;
	int b = handle->len_b;

	t_stack *tmp_a = handle->a;
	t_stack *tmp_b = handle->b;

	printf("\n\tSTATE:\n\n");
	while (a > b)
	{
		printf("%4d\n", tmp_a->content);
		tmp_a = tmp_a->next;
		a--;
	}
	while (a < b)
	{
		printf("%12d\n", tmp_b->content);
		tmp_b = tmp_b->next;
		b--;
	}
	while (a)
	{
		printf("%4d  %6d\n", tmp_a->content, tmp_b->content);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		a--;
		b--;
	}
	printf("<--A-->_<--B-->\n");
}

t_handle *init_stack(int *numbers, int len)
{
	int	i;

	i = len - 1;
	t_handle *handle = (t_handle *) malloc(sizeof(t_handle));
    handle->a = 0;
    handle->b = 0;
	handle->len_a = len;
	handle->len_b = 0;
	handle->max_score = 0;
	handle->max_value = 0;

	while (i >= 0)
	{
		if (push_front(&handle->a, numbers[i]))
		{
			free_lists(handle);
			return (0);
		}
		i--;
	}
	return (handle);
}

void	free_argv(char **argv, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(argv[i]);
	free(argv);
}

int	*parsing(int *argc, char **argv)
{
	int	is_splitted;
	int	*args;

	is_splitted = 0;
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ', argc);
		is_splitted = 1;
	}
	else
		argv++;
	if (validate_numbers(argv, *argc - 1) || overflow(argv, *argc - 1))
	{
		if (is_splitted)
			free_argv(argv, *argc);
		free_and_exit(0, 1, 0);
	}
	args = str_to_num(argv, *argc - 1, is_splitted);
	if (!args)
		free_and_exit(0, 1, 0);
	if (is_repetition(args, *argc - 1))
		free_and_exit(args, 1, 1);
	return (args);
}
