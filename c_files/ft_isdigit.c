/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:53:54 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 15:54:06 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h> 
// #include <stdio.h> 

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

// int main(void)
// {
//     printf ("%d\n", ft_isdigit ('0'));
//     printf ("%d", isdigit ('0'));
//     return (0);
// }