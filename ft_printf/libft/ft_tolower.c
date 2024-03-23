/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:38:27 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:24:08 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

/* #include <stdio.h>

int main() {
	char lowercase = 'Z';
	char uppercase = ft_tolower(lowercase);
	
	printf("Lowercase: %c\n", uppercase);
	
	return 0;
} */