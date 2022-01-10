#include "push_swap.h"
#include "get_next_line.h"

int	do_instruction(t_handle *handle, char *operation)
{
	if (ft_strcmp(operation, "sa") == 0 || ft_strcmp(operation, "sa") == 10)
		ft_sa(handle);
	else if (ft_strcmp(operation, "sb") == 0 || ft_strcmp(operation, "sb") == 10)
		ft_sb(handle);
	else if (ft_strcmp(operation, "pa") == 0 || ft_strcmp(operation, "pa") == 10)
		ft_pa(handle);
	else if (ft_strcmp(operation, "pb") == 0 || ft_strcmp(operation, "pb") == 10)
		ft_pb(handle);
	else if (ft_strcmp(operation, "ra") == 0 || ft_strcmp(operation, "ra") == 10)
		ft_ra(handle);
	else if (ft_strcmp(operation, "rb") == 0 || ft_strcmp(operation, "rb") == 10)
		ft_rb(handle);
	else if (ft_strcmp(operation, "rr") == 0 || ft_strcmp(operation, "rr") == 10)
		ft_rr(handle);
	else if (ft_strcmp(operation, "rra") == 0 || ft_strcmp(operation, "rra") == 10)
		ft_rra(handle);
	else if (ft_strcmp(operation, "rrb") == 0 || ft_strcmp(operation, "rrb") == 10)
		ft_rrb(handle);
	else if (ft_strcmp(operation, "rrr") == 0 || ft_strcmp(operation, "rrr") == 10)
		ft_rrr(handle);
	else
		return (1);
	return (0);
}

void	test_push_swap(t_handle *handle)
{
	char *operation;
	operation = get_next_line(0);
	while (operation)
	{
		if (do_instruction(handle, operation) == 0)
			operation = get_next_line(0);
		else
		{
			write(1, "Error\n", 6);
			return ;
		}
	}
}

int	is_list_sorted(t_handle *handle)
{
	if ()
	int	i;

	i = 0;
	while (handle->a )
		i++;
	if (i == len - 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_handle *handle = 0;
	if (argc < 2)
		return (0);
	int	*args;
	args = parsing(&argc, argv);
	handle = init_stack(args, argc - 1);
	test_push_swap(handle);
	is_list_sorted(handle);
	free_lists(handle);
	free(args);
	return (0);
}
