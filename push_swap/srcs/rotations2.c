/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:42:13 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/13 18:15:33 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_handle *handle, int flag)
{
	t_stack	*tmp;

	if (flag)
		write(1, "ra\n", 3);
	tmp = handle->a;
	handle->a = handle->a->next;
	tmp->prev->next = tmp;
	tmp->next = 0;
}

void	ft_rb(t_handle *handle, int flag)
{
	t_stack	*tmp;

	if (flag)
		write(1, "rb\n", 3);
	tmp = handle->b;
	handle->b = handle->b->next;
	tmp->prev->next = tmp;
	tmp->next = 0;
}
