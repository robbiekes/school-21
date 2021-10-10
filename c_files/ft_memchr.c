/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:29:14 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 19:39:28 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *arr;
    int i = 0;
    int len;
	
	arr = (unsigned char *)s;
	len = ft_strlen(s);
    if (arr == NULL)
        return NULL;
    while(n)
    {
        if (arr[i] == (unsigned char)c)
            return &arr[i];
        n--;
		i++;
    }
    return NULL;
}

// int main(void)
// {
//     char arr[8] = "et8euri";
//     char *ptr;
//     //ptr = memchr(arr, '\0', 8);
// 	ptr = ft_memchr(arr, '/', 8);
//     if (ptr == NULL)
//         printf("res = %s\n", ptr);
//     else
//         printf("res = %ld\n", (ptr-arr)+1);
//     return (0);
// }