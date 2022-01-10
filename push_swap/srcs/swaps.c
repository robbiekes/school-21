/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:19:56 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/05 21:20:53 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_handle *handle)
{
	int	tmp;
	if (handle->a && handle->a->next != handle->a)
	{
		tmp = handle->a->content;
		handle->a->content = handle->a->next->content;
		handle->a->next->content = tmp;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_handle *handle)
{
	int	tmp;
	if (handle->b && handle->b->next != handle->b)
	{
		tmp = handle->b->content;
		handle->b->content = handle->b->next->content;
		handle->b->next->content = tmp;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_handle *handle)
{
	int	tmp;
	
	if (handle->a && handle->a->next != handle->a)
	{
		tmp = handle->a->content;
		handle->a->content = handle->a->next->content;
		handle->a->next->content = tmp;
	}
	if (handle->b && handle->b->next != handle->b)
	{
		tmp = handle->b->content;
		handle->b->content = handle->b->next->content;
		handle->b->next->content = tmp;
	}
	write(1, "ss\n", 3);
}
