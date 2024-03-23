/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:10:33 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:24:01 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = ft_strlen(temp);
	temp += i;
	while (i >= 0)
	{
		if (*temp == (char)c)
			return (temp);
		temp--;
		i--;
	}
	return (NULL);
}

/* 
#include <stdio.h>
#include <string.h>
int main() {
    const char *str = "\0";
    int character = '\0';
    char *result = ft_strrchr(str, character);    
	char *result2 = strrchr(str, character);    
	printf("%s\n", result2);
	printf("%s\n", result);
    return 0;
} */