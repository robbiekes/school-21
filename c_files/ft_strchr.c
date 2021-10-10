/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:57:00 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/09 14:52:03 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlen(const char *s)
// {
	
// 	size_t	i;

// 	i = 0;
// 	while(s[i] != '\0'){
// 		i++;
// 	}
// 	return i;
// }

char *ft_strchr(const char *s, int c)
{
    char *arr;
    int i;
	int len;
	
    i = 0;
	arr = (char *)s;
	len = ft_strlen(arr);
    while(i <= len)
    {
        if (arr[i] == (char)c)
            return &arr[i];
        i++;
    }
    return (0);
}

// int main(void)
// {
//     char arr[5] = "";
//     char *ptr;
//     ptr = strchr(arr, '\0');
//     printf("my ft = %s\n", ptr);
//     return (0);
// }