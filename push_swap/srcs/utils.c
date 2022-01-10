/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:59:23 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/06 16:18:40 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min4(int a, int b, int c, int d)
{
	int	min1;
	int	min2;

	if (a < b)
		min1 = a;
	else
		min1 = b;
	if (c < d)
		min2 = c;
	else
		min2 = d;
	if (min1 < min2)
		return (min1);
	return (min2);
}

int	min2(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	find_start(t_handle *handle)
{
	int	start;
	int	min;

	start = index_a(handle, -2147483647 - 1);
	if (start < handle->len_a - start)
	{
		while (start-- > 0)
			ft_ra(handle);
	}
	else
	{
		while (handle->len_a - start++ > 0)
			ft_rra(handle);
	}
}

int	index_a(t_handle *handle, int num)
{
	t_stack *tmp;
	int	index; /*позиция начала отсортированного стэка*/
	int	i;

	tmp = handle->a;
	i = 0;
	while (tmp != 0)
	{
		if (tmp->content > num && tmp->prev->content < num)
			return (i);
		if (tmp->content < tmp->prev->content)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (index);
}
