/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:55:08 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/09 17:34:18 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void ft_bzero(void *str, size_t bytes)
// {
//     char *arr;
//     arr = (char *)str;
//     while (bytes)
//     {
//         *arr++ = 0;
//         bytes--;
//     }
// }

// int ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	char *arr1;
// 	char *arr2;
// 	size_t	i;

// 	i = 0;
// 	arr1 = (char *)s1;
// 	arr2 = (char *)s2;
// 	while (i < n)
// 	{
// 		if (arr1[i] != arr2[i])
// 			return ((int)(unsigned char)arr1[i] - (unsigned char)arr2[i]);
// 		i++;
// 	}
// 	return (0);
// }

void *ft_calloc(size_t count, size_t size)
{
    void *arr;
    arr = (void *)malloc(size * count);
    if (arr == NULL)
        return (0);
    else
    {
        ft_bzero(arr, count * size);
        return (arr);
    }
}

// int main(void)
// {
// 	int size = 0;
// 	void * d1 = ft_calloc(size, 0);
// 	void * d2 = calloc(size, 0);
// 	if (memcmp(d1, d2, size * 0))
// 		printf("fail\n");
// 	free(d1);
// 	free(d2);
// 	printf("success\n");
//     // char *array;
//     // array = (char *)calloc(5, sizeof(char));
//     // array = "hello";
//     // printf("%s\n", array);
//     return (0);
// }