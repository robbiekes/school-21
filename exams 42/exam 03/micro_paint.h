/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:14:15 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/17 20:23:38 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_field
{
	int		width;
	int		height;
	char	background;
} 			t_field;

typedef struct s_shape
{
	char	rect_type;
	int		width;
	int		height;
	int		x;
	int		y;
	char	c;

}			t_shape;

#endif
