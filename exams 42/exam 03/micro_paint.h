/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:14:15 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/18 17:29:02 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
	int		width;
	int		height;
	char	background;
	FILE 	*file;

	char 	**field;
} 			t_data;

typedef struct s_rect
{
	char	type;
	float	width;
	float	height;
	float	x;
	float	y;
	char	fill;

}			t_rect;

#endif
