/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:54:50 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 16:20:22 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h> 
// #include <stdio.h> 

int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

// int main(void)
// {
//     printf ("%d\n", ft_isalpha (3));
//     printf ("%d", isalpha (3));
//     return (0);
// }