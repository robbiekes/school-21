/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:52:06 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/10 13:08:58 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	int		i;
	char	*dup;
	int		len;

	arr = (char *)s1;
	len = ft_strlen(arr);
	i = 0;
	dup = (char *)malloc(sizeof(char)*len + 1);
	if (dup == NULL)
		return (NULL);
	while (arr[i])
	{
		dup[i] = arr[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char s[12] = "";
// 	char *dup;
// 	dup = ft_strdup(s);
// 	printf("%s\n", dup);
// 	free(dup);
// 	return (0);
// }