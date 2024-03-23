/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:42:34 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:24:57 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitespace(char c)
{
	if (c >= '\t' && c <= '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	sign = 1;
	i = 0;
	n = 0;
	while ((nptr[i] != '\0' && ft_whitespace(nptr[i])) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

/* #include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if(argc == 2)
{
	printf("le resultat du vrai atoi :%d\n", atoi(argv[1]));
	printf("le resultat de mon atoi :%d\n", ft_atoi(argv[1]));
	return(0);
}	return(1);

} */