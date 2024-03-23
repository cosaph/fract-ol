/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:17:57 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:23:05 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_swap(char *result, size_t len)
{
	size_t	i;
	char	temp;

	i = 0;
	while (i < len / 2)
	{
		temp = result[i];
		result[i] = result[len - i - 1];
		result[len - i - 1] = temp;
		i++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		i;
	long	long_n;

	long_n = (long)n;
	if (long_n == 0)
		return (ft_strdup("0"));
	i = 0;
	len = ft_nlen(long_n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (long_n < 0)
	{
		result[len - 1] = '-';
		long_n *= -1;
	}
	while (long_n)
	{
		result[i++] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (ft_swap(result, len));
}

/* char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
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


#include <stdio.h>
int main(){
    char *r;
    
    r = ft_itoa(-2147483648);
    printf("%s",r);
} */