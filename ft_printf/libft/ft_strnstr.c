/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:08:45 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:23:56 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*chaine;

	chaine = (char *)haystack;
	if (!needle[0])
		return (chaine);
	i = 0;
	while (i < len && chaine[i])
	{
		j = 0;
		if (chaine[i] == needle[j])
		{
			while (chaine[i] && needle[j] && chaine[i + j] == needle[j] && i
				+ j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return (chaine + i);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char *ft_strnstr(const char *haystack, const char *needle, size_t len);

// int main() {
//     const char *haystack = "Hello, world!";
//     const char *needle = "world";

//     // Appel de la fonction ft_strnstr et affichage du résultat
//     printf("%s\n", ft_strnstr(haystack, needle, ft_strlen(haystack)));

//     return 0;
// } 