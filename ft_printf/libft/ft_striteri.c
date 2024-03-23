/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:55:24 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:35 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* void ft_example(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = *c - 32;
}

#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	ft_striteri(s, ft_example);
	printf("%s\n", s);
	return 0;
} */