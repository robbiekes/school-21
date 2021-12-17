typedef struct s_stack
{
	unsigned int	content;
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
		tmp = handle->a->content;
		handle->a->content = handle->a->next->content;
		handle->a->next->content = tmp;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_handle *handle) // swap the first two elements of the stack b
{
	unsigned int	tmp;
	if (handle->b && handle->b->next != 0)
	{
		tmp = handle->b->content;
		handle->b->content = handle->b->next->content;
		handle->b->next->content = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_handle *handle) // swap the first two elements of the stacks a and b at the same time
{
	ft_sa(handle);
	ft_sb(handle);
	write(1, "ss\n", 3);
}

void	pushFront(t_handle *handle, char which_stack, int content)
{
	t_stack **recipient;
	t_stack *tmp;

	if (which_stack = 'a')
		recipient = &handle->a;
	else
		recipient = &handle->b;

	tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			return (0);

	if (*recipient)
	{
		tmp->next = *recipient;
		tmp->prev = 0;
		(*recipient)->prev = tmp;
		tmp->content = content;
		(*recipient) = (*recipient)->prev;
	}
	else
	{
		(*recipient)->next = 0;
		(*recipient)->prev = 0;
		(*recipient)->content = content;
	}
}

void	popFront(t_handle *handle, char which_stack) // передали именно t_handle, a не s_stack, потому что t_handle - это пространство, где создаются и хранятся узлы													
{                                                   // s_stack - просто строение узла
	t_stack **donor;
	t_stack *tmp;

	if (which_stack == 'a')
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
	unsigned int	tmp;
	tmp = handle->a->content;

	if (handle->b)
	{
		popFront(handle, 'b');
		pushFront(handle, 'a', tmp);
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_handle *handle) // take the first element at the top of b and put it at the top of a
{
	unsigned int	tmp;
	tmp = handle->b->content;

	if (handle->a)
	{
		popFront(handle, 'a');
		pushFront(handle, 'b', tmp);
		write(1, "pb\n", 3);
	}
}

void	ft_ra(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->a;
	handle->a = handle->a->next; // ????????????????????????
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = handle->a;
	handle->a = 0;
}