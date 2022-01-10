/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:05:43 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:02 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_handle *handle, t_stack *node)
{
	while (node->ra > 0 && node->rb > 0)
	{
		ft_rr(handle);
		node->ra--;
		node->rb--;
	}
	while (node->ra > 0)
	{
		ft_ra(handle);
		node->ra--;
	}
	while (node->rb > 0)
	{
		ft_rb(handle);
		node->rb--;
	}
}

void	do_rev_rotate(t_handle *handle, t_stack *node)
{
	while (node->rra > 0 && node->rrb > 0)
	{
		ft_rrr(handle);
		node->rra--;
		node->rrb--;
	}
	while (node->rra > 0)
	{
		ft_rra(handle);
		node->rra--;
	}
	while (node->rrb > 0)
	{
		ft_rrb(handle);
		node->rrb--;
	}
}

void	rra_and_rb(t_handle *handle, t_stack *node)
{
	while (node->rra > 0)
	{
		ft_rra(handle);
		node->rra--;
	}
	while (node->rb > 0)
	{
		ft_rb(handle);
		node->rb--;
	}
}

void	rrb_and_ra(t_handle *handle, t_stack *node)
{
	while (node->rrb > 0)
	{
		ft_rrb(handle);
		node->rrb--;
	}
	while (node->ra > 0)
	{
		ft_ra(handle);
		node->ra--;
	}
}

void	triple_sort(t_handle *handle, int *nums)
{
	if (nums[0] < nums[2] && nums[1] > nums[2])
	{
		ft_sa(handle);
		ft_ra(handle);
	}
	else if (nums[0] > nums[1] && nums[0] < nums[2])
		ft_sa(handle);
	else if (nums[0] < nums[1] && nums[0] > nums[2])
		ft_rra(handle);
	else if (nums[0] > nums[2] && nums[1] < nums[2])
		ft_ra(handle);
	else if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ft_sa(handle);
		ft_rra(handle);
	}
}
