/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:13:27 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/16 19:23:42 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	finish(int exitcode)
{
	if (exitcode)
		write(1, "Error\n", 6);
	exit(exitcode);
}