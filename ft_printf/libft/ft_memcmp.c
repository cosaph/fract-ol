/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:49:04 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:22:44 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chr1;
	unsigned char	*chr2;

	chr1 = (unsigned char *)s1;
	chr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*chr1 != *chr2)
			return (*chr1 - *chr2);
		chr1++;
		chr2++;
	}
	return (0);
}

/* 
#include <stdio.h>

int main() {
    const char* str1 = "Hello";
    const char* str2 = "Hella";
    size_t len = strlen(str1);

    int result = ft_memcmp(str1, str2, len);

    if (result == 0) {
        printf("identiques.\n");
    } else if (result < 0) {
        printf(" inférieure \n");
    } else {
        printf("supérieure\n");
    }
    return 0;
} */