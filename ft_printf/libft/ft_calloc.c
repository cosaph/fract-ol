/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:20:46 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:24:46 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > 2147483647 / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/* 
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i++ < n)
	{
		*temp = '\0';
		temp++;
	}
}

#include <stdio.h>
#include <strings.h>
int main()
{
 	int *result = ft_calloc(3, 4);
    int *true_result = calloc(3,4);
    for (int i = 0; i < 12; i++)
    {
		printf("%d", result[i]);
        printf("%c", ' ');
        printf("%d\n", true_result[i]); 
	}
	return(0);	
} */