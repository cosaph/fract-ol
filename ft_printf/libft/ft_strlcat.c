/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:43:00 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:41 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	if (!dst && n == 0)
		return (0);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	j = 0;
	if (n <= len_dst)
		return (n + len_src);
	while (src[j] && i < (n - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    char destination[20] = "Hello,";
    const char *source = "world!";
	size_t m;
	size_t n;
	char destinationn[20] = "Hello,";
    const char *sourcee = "world!";

    
    size_t destination_size = sizeof(destination);
    size_t destination_length = strlen(destination);
    size_t source_length = strlen(source);
    
    size_t total_length = destination_length + source_length;
    
    if (total_length < destination_size) {
		m = ft_strlcat(destination, source, destination_size);
		printf("ft_strlcat: %zu\n", m);

		n = strlcat(destinationn, sourcee, destination_size);
		printf("strlcat: %zu\n", n);
    } else {
        return (1);
    }
    
    return 0;
} */