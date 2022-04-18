/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:41:50 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/13 18:15:25 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflow(char **argv, int len)
{
	int	i;
	int	neg;
	int	pos;

	i = 0;
	while (i < len)
	{
		neg = (argv[i][0] == '-');
		pos = (argv[i][0] == '+');
		if (ft_strlen(argv[i]) - neg - pos > 10)
			return (1);
		if (neg && ft_strlen(argv[i]) - neg - pos == 10
			&& ft_strcmp(argv[i], "-2147483648") > 0)
			return (1);
		if (!neg && ft_strlen(argv[i]) - neg - pos == 10
			&& ft_strcmp(&argv[i][pos], "2147483647") > 0)
			return (1);
		i++;
	}
	return (0);
}

int	*str_to_num(char **argv, int len, int is_splitted)
{
	int	i;
	int	*final_args;

	final_args = (int *)malloc(sizeof(int) * len);
	if (!final_args)
	{
		if (is_splitted)
			free_argv(argv, len + 1);
		return (0);
	}
	i = -1;
	while (++i < len)
		final_args[i] = ft_atoi(argv[i]);
	if (is_splitted)
		free_argv(argv, len + 1);
	return (final_args);
}

int	is_repetition(int *args, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (args[j] == args[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_numbers(char **av, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (av[i][0] == '-')
			j++;
		if (av[i][j] == 0)
			return (0);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
