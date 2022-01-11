/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:19:56 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/11 16:25:58 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_handle *handle, int flag)
{
	int	tmp;

	if (flag)
		write(1, "sa\n", 3);
	if (handle->a && handle->a->next != handle->a)
	{
		tmp = handle->a->content;
		handle->a->content = handle->a->next->content;
		handle->a->next->content = tmp;
	}
}

void	ft_sb(t_handle *handle, int flag)
{
	int	tmp;

	if (flag)
		write(1, "sb\n", 3);
	if (handle->b && handle->b->next != handle->b)
	{
		tmp = handle->b->content;
		handle->b->content = handle->b->next->content;
		handle->b->next->content = tmp;
	}
}

void	ft_ss(t_handle *handle, int flag)
{
	int	tmp;
	
	if (flag)
		write(1, "ss\n", 3);
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
}
