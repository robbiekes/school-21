/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:42:24 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/11 20:03:19 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	do_instruction(t_handle *handle, char *operation)
{
	if (ft_strcmp(operation, "sa") == 0 || ft_strcmp(operation, "sa") == 10)
		ft_sa(handle, 0);
	else if (ft_strcmp(operation, "sb") == 0 || ft_strcmp(operation, "sb") == 10)
		ft_sb(handle, 0);
	else if (ft_strcmp(operation, "pa") == 0 || ft_strcmp(operation, "pa") == 10)
		ft_pa(handle, 0);
	else if (ft_strcmp(operation, "pb") == 0 || ft_strcmp(operation, "pb") == 10)
		ft_pb(handle, 0);
	else if (ft_strcmp(operation, "ra") == 0 || ft_strcmp(operation, "ra") == 10)
		ft_ra(handle, 0);
	else if (ft_strcmp(operation, "rb") == 0 || ft_strcmp(operation, "rb") == 10)
		ft_rb(handle, 0);
	else if (ft_strcmp(operation, "rr") == 0 || ft_strcmp(operation, "rr") == 10)
		ft_rr(handle, 0);
	else if (ft_strcmp(operation, "rra") == 0 || ft_strcmp(operation, "rra") == 10)
		ft_rra(handle, 0);
	else if (ft_strcmp(operation, "rrb") == 0 || ft_strcmp(operation, "rrb") == 10)
		ft_rrb(handle, 0);
	else if (ft_strcmp(operation, "rrr") == 0 || ft_strcmp(operation, "rrr") == 10)
		ft_rrr(handle, 0);
	else
		return (1);
	return (0);
}

int	is_list_sorted(t_handle *handle)
{
	t_stack	*tmp;

	if (handle->b)
		return (0);
	tmp = handle->a;
	while (tmp->next != 0)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	test_push_swap(t_handle *handle)
{
	char	*operation;
	
	operation = get_next_line(0);
	while (operation && operation[0] != '\n')
	{
		if (do_instruction(handle, operation) == 1)
		{
			write(1, "Error\n", 10);
			free(operation);
			return ;
		}
		free(operation);
		operation = get_next_line(0);
	}
	if (is_list_sorted(handle))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_handle *handle;

	handle = 0;
	if (argc < 2)
		return (0);
	int	*args;
	args = parsing(&argc, argv);
	handle = init_stack(args, argc - 1);
	test_push_swap(handle);
	//print_state(handle);
	free_lists(handle);
	free(args);
	return (0);
}
