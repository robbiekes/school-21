/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:26:53 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 19:40:10 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	
	size_t	i;

	i = 0;
	while(s[i] != '\0'){
		i++;
	}
	return i;
}
// int main(void)
// {
//     char arr[6] = "";
//     int len = ft_strlen(arr);
// 	printf("%d\n", len);
//     return (0);
// }