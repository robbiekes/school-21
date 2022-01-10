#include "push_swap.h"

void	free_stack(t_stack *node)
{
	t_stack *tmp;
	t_stack *delete;

	tmp = node;
	while(tmp->next != 0)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete);
	}
	free(tmp);
}

void	free_lists(t_handle *handle)
{
	if (handle->a)
		free_stack(handle->a);
	if (handle->b)
		free_stack(handle->b);
	free(handle);
}