/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:19:51 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 17:10:11 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex	mappoint(t_fractal *fractal, double x, double y)
{
	t_complex	c;
	double		l;

	if (fractal->width < fractal->height)
		l = fractal->height * fractal->zoom;
	else
		l = fractal->width * fractal->zoom;
	x += fractal->xarrow ;
	y += fractal->yarrow ;
	c.x = 2 * fractal->radius * (x - fractal->width / 2) / l;
	c.y = 2 * fractal->radius * (y - fractal->height / 2) / l;
	return (c);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
