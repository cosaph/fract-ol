/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:14:32 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 17:10:26 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	mandelbrot_param(t_fractal *fractal, char *name)
{
	fractal->width = 800;
	fractal->height = 800;
	fractal->iterations = 50;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = PSYCHEDELIC_WARM;
	fractal->name = name;
}

void	julia_param(t_fractal *fractal, char *name, double cx, double cy)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->c.x = cx;
	fractal->c.y = cy;
	fractal->radius = 3;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = PSYCHEDELIC_WARM;
	fractal->name = name;
}

void	ikeda_param(t_fractal *fractal, char *name)
{
	fractal->width = 800;
	fractal->height = 800;
	fractal->u = 0.9;
	fractal->iterations = 10000000;
	fractal->color = PSYCHEDELIC_WARM;
	fractal->name = name;
}
