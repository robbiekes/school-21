/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:23:04 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/13 18:13:20 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_front(t_stack **stack_a, int content)
{
	t_stack	**new;
	t_stack	*tmp;

	new = stack_a;
	if (*new)
	{
		tmp = (t_stack *) malloc(sizeof(t_stack));
		if (!tmp)
			return (1);
		tmp->next = *new;
		tmp->prev = (*new)->prev;
		(*new)->prev = tmp;
		tmp->content = content;
		(*new) = (*new)->prev;
	}
	else
	{
		*new = (t_stack *) malloc(sizeof(t_stack));
		if (!(*new))
			return (1);
		(*new)->next = 0;
		(*new)->prev = *new;
		(*new)->content = content;
	}
	return (0);
}

void	pop_front(t_handle *handle, char which_stack)
{
	t_stack	**donor;
	t_stack	*tmp;

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
			free(tmp);
		}
	}
}

void	ft_pa(t_handle *handle, int flag)
{
	t_stack	*temp;

	if (flag)
		write(1, "pa\n", 3);
	if (!handle->b)
		return ;
	temp = handle->b;
	handle->b = handle->b->next;
	if (handle->b)
		handle->b->prev = temp->prev;
	if (handle->a == 0)
	{
		temp->prev = temp;
		temp->next = 0;
	}
	else
	{
		temp->prev = handle->a->prev;
		handle->a->prev = temp;
		temp->next = handle->a;
	}
	handle->a = temp;
	handle->len_b--;
	handle->len_a++;
}

void	ft_pb(t_handle *handle, int flag)
{
	t_stack	*temp;

	if (flag)
		write(1, "pb\n", 3);
	if (handle->a)
	{
		temp = handle->a;
		handle->a = handle->a->next;
		if (handle->a != 0)
			handle->a->prev = temp->prev;
		if (handle->b == 0)
		{
			temp->prev = temp;
			temp->next = 0;
		}
		else
		{
			temp->next = handle->b;
			temp->prev = handle->b->prev;
			handle->b->prev = temp;
		}
		handle->b = temp;
		handle->len_b++;
		handle->len_a--;
	}
}
