/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:54:34 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:33 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp)
	{
		if (*temp == (char)c)
			return (temp);
		temp++;
	}
	if (c == '\0')
		return (temp);
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
int main() {
    const char *str = "hello WorldW!";
    int character = 'W';
    char *result = ft_strchr(str, character);    
    printf("Character '%c' found at position: %ld\n", character, result-str);
    return 0;
}  */