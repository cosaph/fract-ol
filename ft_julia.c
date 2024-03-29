/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:18:20 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 16:22:43 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	juliaset(t_fractal *julia)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	julia->x = 0;
	while (++julia->x <= julia->width)
	{
		julia->y = 0;
		while (++julia->y <= julia->height)
		{
			z0 = mappoint(julia, julia->x, julia->y);
			i = 1;
			while (i++ <= julia->iterations)
			{
				z1 = sum_complex(square_complex(z0), julia->c);
				if (z1.x * z1.x + z1.y * z1.y > julia->radius * julia->radius)
				{
					my_mlx_pixel_put(julia, julia->x,
						julia->y, julia->color * i);
					break ;
				}
				z0 = z1;
			}
		}
	}
}
