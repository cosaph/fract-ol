/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:33:54 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:23:31 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *s1, const char *s2, size_t n )
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i] && str1[i] != '\0')
		&& str2[i] != '\0' && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

/* 
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	if (argc == 4)
		printf("ft_strncmp: %d\n",ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("vrai strncmp: %d\n",strncmp(argv[1], argv[2], atoi(argv[3])));
} 
 */