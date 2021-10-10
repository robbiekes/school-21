/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:24:01 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 19:55:50 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *arr1;
	char *arr2;
	size_t	i;

	i = 0;
	arr1 = (char *)s1;
	arr2 = (char *)s2;
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return ((int)(unsigned char)arr1[i] - (unsigned char)arr2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
    char s1[100] = "qwe\0qw\200";
    char s2[100] = "";
    printf("my ft memcmp = %d\n", ft_memcmp(s1, s2, 7));
    printf("orig = %d\n", memcmp(s1, s2, 7));
    return (0);
}*/