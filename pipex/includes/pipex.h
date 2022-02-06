/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:11:08 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/06 19:35:28 by mgwyness         ###   ########.fr       */
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
#include <stdio.h>

char	**ft_split(char *s, char c);
char	*ft_substr(char **s, unsigned int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *dst, char *src);
int		ft_strlen(char *s);
char	*pathjoin(char *s1, char *s2);


#endif