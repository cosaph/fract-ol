/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:06:36 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:24:11 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* #include <stdio.h>

int ft_toupper(int c);

int main() {
    char lowercase = '+';
    char uppercase = ft_toupper(lowercase);
    
    printf("Uppercase: %c\n", uppercase);
    
    return 0;
    
} */