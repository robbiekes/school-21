/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:12:54 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/09 15:07:16 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *arr1;
	char *arr2;
	size_t	i;

	i = 0;
	arr1 = (char *)s1;
	arr2 = (char *)s2;
	while (i < n)
	{
		if ((arr1[i] != arr2[i]) || arr1[i] == '\0' || arr2[i] == '\0')
			return ((int)((unsigned char)arr1[i] - (unsigned char)arr2[i]));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char s1[5] = "";
//     char s2[5] = "abcd1";
//     printf("my ft = %d\n", ft_strncmp(s1, s2, 5));
//     printf("orig = %d\n", strncmp(s1, s2, 5));
//     return (0);
// }