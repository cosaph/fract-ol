/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:02:47 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:23:40 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* 
#include <stdio.h>

int main(void)
{
	int chf;

	chf = '1';

	printf("%d\n",ft_isdigit(chf));
	printf("%d\n",isdigit(chf));
}  */