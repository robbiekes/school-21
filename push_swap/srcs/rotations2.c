/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:42:13 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/06 15:02:46 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->a;
	handle->a = handle->a->next;
    tmp->prev->next = tmp;
    tmp->next = 0;
	write(1, "ra\n", 3);
}

void	ft_rb(t_handle *handle)
{
	t_stack *tmp;
	tmp = handle->b;
	handle->b = handle->b->next;
    tmp->prev->next = tmp;
    tmp->next = 0;
	write(1, "rb\n", 3);
}
