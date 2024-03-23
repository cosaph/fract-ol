/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:28:07 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:22:49 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    const char* str = "Hello, world!";
    char target = 'w';
    size_t len = strlen(str);

    void* result = memchr(str, target, len);
	void* result_bis = ft_memchr(str, target, len);

    if (result != NULL) {
        size_t index = (char*)result - str;
		size_t index_bis = (char *)result_bis - str;

        printf("Caractère trouvé  %zu\n", index);
		printf("Caractère trouvé %zu\n", index_bis);
    } else {
        printf("Caractère non trouvé\n");
    }

    return 0;
} */