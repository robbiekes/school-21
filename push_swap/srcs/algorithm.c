/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:41:20 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/06 16:20:17 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_sorted(int *nums, int len, int max_score)
{
	int	i;
	int	j;
	int	max_value;
	int	index;
	int	score;

	i = -1;
	while (++i < len)
	{
		j = (i + 1) % len;
		max_value = nums[i];
		score = 1;
		while (j != i)
		{
			if (nums[j] > max_value)
				max_value = nums[j] + (score++ < 0);
			j = (j + 1) % len;
		}
		if (score > max_score)
		{
			max_score = score;
			index = i;
		}
	}
	return (index);
}

/* line 33 -> j++; if j == len, then j = 0; */
 
void	fill_stack_b(t_handle *handle, int *nums, int index)
{
	int	i;
	int	j;
	int	max_value;
	
	i = index + 1;
	max_value = nums[index];
	while (i < handle->len_a)
	{
		if (nums[i] > max_value)
			max_value = nums[i];
		i++;
	}
	while (i > 0)
	{
		if ((handle->len_a + handle->len_b) - i == index)
			max_value = -2147483647 - 1;
		if (handle->a->content >= max_value)
		{
			max_value = handle->a->content;
			ft_ra(handle);
		}
		else
			ft_pb(handle);
		i--;
	}
}

t_stack	*min_steps_node(t_handle *handle)
{
	int	i;
	int	min_steps;
	t_stack	*node;
	t_stack	*tmp;

	i = 0;
	tmp = handle->b;
	min_steps = 2147483647;
	while (tmp != 0)
	{
		tmp->ra = index_a(handle, tmp->content);
		tmp->rra = handle->len_a - tmp->ra;
		tmp->rb = i;
		tmp->rrb = handle->len_b - i;
		if (min4(max(tmp->ra, tmp->rb), tmp->rrb + tmp->ra,
			tmp->rb + tmp->rra, max(tmp->rra, tmp->rrb)) < min_steps)
		{
			min_steps = min4(max(tmp->ra, tmp->rb), tmp->rrb + tmp->ra,
				tmp->rra + tmp->rb, max(tmp->rra, tmp->rrb));
			node = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	return (node);
}

void	do_operations(t_handle *handle)
{
	t_stack	*tmp;
	int	min_steps;
	int	i;

	i = 0;
	tmp = min_steps_node(handle);
	min_steps = min4(max(tmp->ra, tmp->rb), tmp->rrb + tmp->ra,
		tmp->rb + tmp->rra, max(tmp->rra, tmp->rrb));
	if (min_steps == max(tmp->ra, tmp->rb))
		do_rotate(handle, tmp);
	else if (min_steps == max(tmp->rra, tmp->rrb))
		do_rev_rotate(handle, tmp);
	else if (min_steps == (tmp->ra + tmp->rrb))
		rrb_and_ra(handle, tmp);
	else
		rra_and_rb(handle, tmp);
	ft_pa(handle);
}

void	push_swap(t_handle *handle, int *nums)
{
	if (handle->len_a == 3)
	{
		triple_sort(handle, nums);
		return ;
	}
	fill_stack_b(handle, nums, max_sorted(nums, handle->len_a, 0));
	while (handle->len_b > 0)
		do_operations(handle);
	find_start(handle);
	//print_state(handle);
}
