/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:05:43 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/11 16:27:59 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_handle *handle, t_stack *node)
{
	while (node->ra > 0 && node->rb > 0)
	{
		ft_rr(handle, 1);
		node->ra--;
		node->rb--;
	}
	while (node->ra > 0)
	{
		ft_ra(handle, 1);
		node->ra--;
	}
	while (node->rb > 0)
	{
		ft_rb(handle, 1);
		node->rb--;
	}
}

void	do_rev_rotate(t_handle *handle, t_stack *node)
{
	while (node->rra > 0 && node->rrb > 0)
	{
		ft_rrr(handle, 1);
		node->rra--;
		node->rrb--;
	}
	while (node->rra > 0)
	{
		ft_rra(handle, 1);
		node->rra--;
	}
	while (node->rrb > 0)
	{
		ft_rrb(handle, 1);
		node->rrb--;
	}
}

void	rra_and_rb(t_handle *handle, t_stack *node)
{
	while (node->rra > 0)
	{
		ft_rra(handle, 1);
		node->rra--;
	}
	while (node->rb > 0)
	{
		ft_rb(handle, 1);
		node->rb--;
	}
}

void	rrb_and_ra(t_handle *handle, t_stack *node)
{
	while (node->rrb > 0)
	{
		ft_rrb(handle, 1);
		node->rrb--;
	}
	while (node->ra > 0)
	{
		ft_ra(handle, 1);
		node->ra--;
	}
}

void	triple_sort(t_handle *handle, int *nums)
{
	if (nums[0] < nums[2] && nums[1] > nums[2])
	{
		ft_sa(handle, 1);
		ft_ra(handle, 1);
	}
	else if (nums[0] > nums[1] && nums[0] < nums[2])
		ft_sa(handle, 1);
	else if (nums[0] < nums[1] && nums[0] > nums[2])
		ft_rra(handle, 1);
	else if (nums[0] > nums[2] && nums[1] < nums[2])
		ft_ra(handle, 1);
	else if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ft_sa(handle, 1);
		ft_rra(handle, 1);
	}
}
