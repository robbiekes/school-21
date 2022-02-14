/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:24:20 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/14 17:30:51 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_BONUS_H
#define PIPE_BONUS_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef	struct s_data
{
	int	fd1;
	int	fd2;
	int	ac;
	char **av;
	char **env;
	int	tube1[2];
	int	tube2[2];
	char *limiter;
}	t_data;

char	**ft_split(char *s, char c);
char	*ft_strcat(char *dst, char *src);
int		ft_strlen(char *s);
char	*pathjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
void	get_input(t_data *data);


#endif