/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:24:20 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/08 19:28:50 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
#define PIPE_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char	**ft_split(char *s, char c);
char	*ft_strcat(char *dst, char *src);
int		ft_strlen(char *s);
char	*pathjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

typedef	struct s_data
{
	int	fd1;
	int	fd2;
}	t_data;

#endif