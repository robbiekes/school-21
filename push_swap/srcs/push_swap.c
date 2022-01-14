/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:12:11 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/13 18:08:40 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_handle	*handle;
	int			*args;

	if (argc < 2)
		return (0);
	args = parsing(&argc, argv);
	handle = init_stack(args, argc - 1);
	push_swap(handle, args);
	free_lists(handle);
	free(args);
	return (0);
}
