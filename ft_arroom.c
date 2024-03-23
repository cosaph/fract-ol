/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:29:43 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 16:35:49 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	close_fractal(t_fractal	*fractal)
{
	freeall(fractal);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_zoom(double x, double y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = x / fractal->zoom;
	mouse_y = y / fractal->zoom;
	fractal->x -= (mouse_x - fractal->mouse_x) / fractal->zoom;
	fractal->y -= (mouse_y - fractal->mouse_y) / fractal->zoom;
	fractal->zoom *= 1.3;
	fractal->iterations++;
	fractal->mouse_x = mouse_x;
	fractal->mouse_y = mouse_y;
}

void	ft_dezoom(double x, double y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = x / fractal->zoom;
	mouse_y = y / fractal->zoom;
	fractal->x -= (mouse_x - fractal->mouse_x) / fractal->zoom;
	fractal->y -= (mouse_y - fractal->mouse_y) / fractal->zoom;
	fractal->zoom /= 1.3;
	fractal->iterations--;
	fractal->mouse_x = mouse_x;
	fractal->mouse_y = mouse_y;
}

int	key_hook(int keycode, t_fractal *fractal, double cx, double cy)
{
	if (keycode == ESC)
		close_fractal(fractal);
	else if (keycode == LEFT)
		fractal->xarrow -= 30;
	else if (keycode == DOWN)
		fractal->yarrow += 30;
	else if (keycode == RIGHT)
		fractal->xarrow += 30;
	else if (keycode == UP)
		fractal->yarrow -= 30;
	else if (keycode == PLUS)
		fractal->color += 100;
	else if (keycode == MINUS)
		fractal->color -= 100;
	else if (keycode == R)
	{
		ft_printf("Reset time!\n");
		julia_param(fractal, fractal->name, cx, cy);
	}
	else if (keycode == Z)
		fractal->zoom = 1;
	if (keycode != ESC)
		fractalsetup(fractal);
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	if (key_code == 1 && !ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->c.x = ((double)x / fractal->width * 4 - 2);
		fractal->c.y = ((double)y / fractal->height * 3 - 1.5);
		fractal->zoom = 1;
	}
	else if (key_code == 4)
		ft_zoom(x, y, fractal);
	else if (key_code == 5)
		ft_dezoom(x, y, fractal);
	fractalsetup(fractal);
	return (0);
}
