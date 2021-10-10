/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:39:56 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 19:57:35 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *arr;
	int	len;
	
	arr = (char *)s;
	len = ft_strlen(arr);
	if (arr == NULL)
		return NULL;
	while(len >= 0)
	{
		if (arr[len] == (char)c)
			return &arr[len];
		len--;
	}
	return NULL;
}

// int main(void)
// {
//     char arr[100] = "111111";
//     char *ptr1;
//     char *ptr2;
// 	char a = '1';
//     ptr1 = ft_strrchr(0, a);
// 	ptr2 = strrchr(0, a);
	
//     printf("my ft = (%s)\n", ptr1);
//     printf("my ft = (%s)\n", ptr2);
// }
