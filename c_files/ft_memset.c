/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:58:07 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 20:04:13 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *arr;
    arr = (unsigned char *)b;
    while(len)
    {
        *arr++ = (unsigned char)c;
        len--;
    }
    return (b);
}

// int main(void)
// {
//     char arr[9] = "ajhdkjdj";
//     ft_memset(arr+2, 'R', 4*sizeof(char));
//     int n = 0;
//     while(n < 9)
//     {
//         printf("%c", arr[n]);
//         n++;
// 	}
//     return (0);
// }