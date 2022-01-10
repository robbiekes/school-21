/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:27:00 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/05 21:27:15 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->a;
	handle->a = handle->a->next;
    tmp->prev->next = tmp;
    tmp->next = 0;

	tmp = handle->b;
	handle->b = handle->b->next;
    tmp->prev->next = tmp;
    tmp->next = 0;

	write(1, "rr\n", 3);
}

void	ft_rra(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->a->prev;
	tmp->next = handle->a;
	handle->a = tmp;
	tmp->prev->next = 0;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->b->prev;
	tmp->next = handle->b;
	handle->b = tmp;
	tmp->prev->next = 0;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->a->prev;
	tmp->next = handle->a;
	handle->a = tmp;
	tmp->prev->next = 0;

	tmp = handle->b->prev;
	tmp->next = handle->b;
	handle->b = tmp;
	tmp->prev->next = 0;
	write(1, "rrr\n", 4);
}
