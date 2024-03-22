/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:29:43 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/22 13:53:04 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
// TO DO ZOOM + ARROW + CLOSING THE WINDOW PROPERLY

void ft_zoom(double x, double y, t_fractal *fractal)
{
    double mouse_x = x / fractal->zoom;
    double mouse_y = y / fractal->zoom;

    fractal->x = (mouse_x - (fractal->width / 2)) / (fractal->zoom * 1.3) + (fractal->width / 2);
    fractal->y = (mouse_y - (fractal->height / 2)) / (fractal->zoom * 1.3) + (fractal->height / 2);
    fractal->zoom *= 1.3;
    fractal->iterations++;
}

void ft_dezoom(double x, double y, t_fractal *fractal)
{
    double mouse_x = x / fractal->zoom;
    double mouse_y = y / fractal->zoom;

    fractal->x = (mouse_x - (fractal->width / 2)) / (fractal->zoom / 1.3) + (fractal->width / 2);
    fractal->y = (mouse_y - (fractal->height / 2)) / (fractal->zoom / 1.3) + (fractal->height / 2);
    fractal->zoom /= 1.3;
    fractal->iterations--;
}

int		close_fractal(t_fractal	*fractal)
{
	freeall(fractal);
	exit(EXIT_SUCCESS);
	return(EXIT_SUCCESS);
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
		printf("Reset time!\n"); //a changer
		julia_param(fractal, fractal->name, cx, cy);
	}
	else if (keycode == Z)
		fractal->zoom = 1;
	if (keycode != ESC)
		fractalsetup(fractal);
	return (0);
}

int mouse_hook(int key_code, int x, int y, t_fractal *fractal)
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