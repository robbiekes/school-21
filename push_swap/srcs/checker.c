/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:42:24 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/13 18:46:10 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	do_instruction(t_handle *handle, char *actions)
{
	if (ft_strcmp(actions, "sa") == 0 || ft_strcmp(actions, "sa") == 10)
		ft_sa(handle, 0);
	else if (ft_strcmp(actions, "sb") == 0 || ft_strcmp(actions, "sb") == 10)
		ft_sb(handle, 0);
	else if (ft_strcmp(actions, "pa") == 0 || ft_strcmp(actions, "pa") == 10)
		ft_pa(handle, 0);
	else if (ft_strcmp(actions, "pb") == 0 || ft_strcmp(actions, "pb") == 10)
		ft_pb(handle, 0);
	else if (ft_strcmp(actions, "ra") == 0 || ft_strcmp(actions, "ra") == 10)
		ft_ra(handle, 0);
	else if (ft_strcmp(actions, "rb") == 0 || ft_strcmp(actions, "rb") == 10)
		ft_rb(handle, 0);
	else if (ft_strcmp(actions, "rr") == 0 || ft_strcmp(actions, "rr") == 10)
		ft_rr(handle, 0);
	else if (ft_strcmp(actions, "rra") == 0 || ft_strcmp(actions, "rra") == 10)
		ft_rra(handle, 0);
	else if (ft_strcmp(actions, "rrb") == 0 || ft_strcmp(actions, "rrb") == 10)
		ft_rrb(handle, 0);
	else if (ft_strcmp(actions, "rrr") == 0 || ft_strcmp(actions, "rrr") == 10)
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
	char	*actions;

	actions = get_next_line(0);
	while (actions && actions[0] != '\n')
	{
		if (do_instruction(handle, actions) == 1)
		{
			write(1, "Error\n", 6);
			free(actions);
			return ;
		}
		free(actions);
		actions = get_next_line(0);
	}
	if (is_list_sorted(handle))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_handle	*handle;
	int			*args;

	handle = 0;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	args = parsing(&argc, argv);
	handle = init_stack(args, argc - 1);
	test_push_swap(handle);
	free_lists(handle);
	free(args);
	return (0);
}
