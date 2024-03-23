/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:14:41 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:19:33 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/* void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putstr_fd(argv[1], atoi(argv[2]));
		return(0);
	}
	return(1);
}  */