/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:12:00 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/18 09:08:44 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	minimandel(int x, int y, t_fractal *mandel)
{
	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	mandel->c.x = (x + mandel->xarrow) / mandel->zoom
		* (0.47 + 2.0) / (mandel->width - 1) - 2.0;
	mandel->c.y = (y + mandel->yarrow) / mandel->zoom
		* (1.12 + 1.12) / (mandel->width - 1) - 1.12;
	z0 = mandel->c.x;
	z1 = mandel->c.y;
	while (i++ < mandel->iterations)
	{
		tempz0 = z0 * z0 - z1 * z1 + mandel->c.x;
		z1 = 2.0 * z0 * z1 + mandel->c.y;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			my_mlx_pixel_put(mandel, (int) x, (int) y, (mandel->color * i));
			break ;
		}
	}
}

void	mandelbrotset(t_fractal *mandel)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= mandel->width)
	{
		y = -1;
		while (++y <= mandel->height)
		{
			minimandel(x, y, mandel);
		}
	}
}