/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:31:23 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:24:06 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_result;
	char	*result;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		result = ft_calloc(1, 1);
		if (!result)
			return (NULL);
	}
	else
	{
		if (len_s - start > len)
			len_result = len;
		else
			len_result = len_s - start;
		result = (char *)malloc((len_result + 1) * sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, s + start, len + 1);
	}
	return (result);
}

/* #include <stdio.h>

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


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	if (size && count > __SIZE_MAX__ / size)
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
int main(void)
{
	char *str;
	char *ptr;

	str = "helloworld!";
	ptr = ft_substr(str, 2, 5);
	printf("%s\n", ptr);
} */