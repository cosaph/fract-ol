/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:04:54 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:42 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/* #include <stdio.h>
#include <string.h>


int main() {
	char destination[13];
	const char *source ="Hello world!";

	printf("%ld\n",ft_strlcpy(destination, source, sizeof(destination)));

	printf("Destination ft_strlcpy: %s\n", destination);

	printf("%ld\n",strlcpy(destination, source, sizeof(destination)));

	printf("Destination strlcpy: %s\n", destination);


	return 0;
} */