/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ideka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:32:06 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 18:36:14 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	calculatecoordinates(t_fractal *ikeda, double *x, double *y)
{
	double	t;
	double	x_new;
	double	y_new ;

	t = 0.4 - 6.0 / (1.0 + (*x * *x + *y * *y));
	x_new = 1.0 + ikeda->u * (*x * cos(t) - *y * sin(t));
	y_new = ikeda->u * (*x * sin(t) + *y * cos(t));
	*x = x_new;
	*y = y_new;
}

static void	drawpixel(t_fractal *ikeda, int pixel_x, int pixel_y, int color)
{
	if (pixel_x >= 0 && pixel_x < ikeda->width && pixel_y >= 0
		&& pixel_y < ikeda->height)
		my_mlx_pixel_put(ikeda, pixel_x, pixel_y, color);
}

void	ikedaattractor(t_fractal *ikeda)
{
	int		i;
	double	x;
	double	y;
	int		pixel_x;
	int		pixel_y;

	i = 0;
	x = 0.1;
	y = 0.0;
	while (i < ikeda->iterations)
	{
		calculateCoordinates(ikeda, &x, &y);
		pixel_x = ikeda->width / 2 + x * ikeda->width / 5;
		pixel_y = ikeda->height / 2 + y * ikeda->height / 5;
		drawPixel(ikeda, pixel_x, pixel_y, ikeda->color * i);
		i++;
	}
}
