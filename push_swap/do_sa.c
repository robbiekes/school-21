typedef struct s_stack
{
	unsigned int	num;
	struct s_stack *next;
	struct s_stack *prev;
}					t_stack;

typedef struct s_handle
{
	unsigned int	size;
	t_stack			*a;
	t_stack			*b;
} 					t_handle;

void	ft_sa(t_handle *handle) // swap the first two elements of the stack a
{
	unsigned int tmp;
	if (handle->a && handle->a->next != 0)
	{
		tmp = handle->a->num;
		handle->a->num = handle->a->next->num;
		handle->a->next->num = tmp;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_handle *handle) // swap the first two elements of the stack b
{
	unsigned int	tmp;
	if (handle->b && handle->b->next != 0)
	{
		tmp = handle->b->num;
		handle->b->num = handle->b->next->num;
		handle->b->next->num = tmp;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_handle *handle) // swap the first two elements of the stacks a and b at the same time
{
	ft_sa(handle);
	ft_sb(handle);
	write(1, "ss\n", 3);
}

void	popElement(t_handle *handle, char stack_name) // почему передали именно t_handle, a не s_stack????????????
{
	t_stack **donor;
	t_stack *tmp;

	if (stack_name == 'a')
		donor = &handle->a;
	else
		donor = &handle->b;

	if (*donor)
	{
		if ((*donor)->next == 0)
		{
			free(donor);
			*donor = 0;
		}
		else
		{
			tmp = *donor;
			*donor = (*donor)->next;
			tmp->prev->next = *donor;
			(*donor)->next = tmp->prev;
			free(tmp);
		}
	}
}

void	ft_pa(t_handle *handle) // take the first element at the top of b and put it at the top of a
{

}