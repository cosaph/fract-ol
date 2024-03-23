/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:37:24 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:23:23 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_w(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	ft_free_result(char **result, int count)
{
	while (count > -1)
	{
		free(result[count]);
		count--;
	}
	free(result);
}

int	ft_fill_result(char **result, char c, char const *s, int count)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			result[count] = (char *)malloc((j - i + 1) * sizeof(char));
			if (!result[count])
			{
				ft_free_result(result, count);
				return (0);
			}
			ft_strlcpy(result[count++], s + i, j - i + 1);
			i = j;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nbr_mots;
	char	**result;

	if (!s)
		return (NULL);
	nbr_mots = ft_count_w(s, c);
	result = (char **)malloc((nbr_mots + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_fill_result(result, c, s, 0))
		return (NULL);
	*(result + nbr_mots) = NULL;
	return (result);
}

/* 
int	ft_strlcpy(char *dst, const char *src, int size)
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
int main(void)
{
	char **res = ft_split("hellochello", 'c');
	int i = 0;
	while (res[i])
	{
		printf("t[%d] = %s\n", i, res[i]);
		i++;
	}
	printf("%s",res[i]);
}  */