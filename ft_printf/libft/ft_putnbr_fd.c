/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:52:13 by cosaph            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:59 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;
	int	nbr;

	sign = -1;
	nbr = n;
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * sign;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
	}
	ft_putchar_fd(nbr % 10 + 48, fd);
}

/*  
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!(s) || !(fd))
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\0', fd);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
		return(0);
	}
	return(1);
} */