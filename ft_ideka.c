/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ideka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:32:06 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 17:24:06 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ikedaattractor(t_fractal *ikeda)
{
	int	i;

	i = 0;
	while (i < ikeda->iterations)
	{
		ikeda->t = 0.4 - 6.0 / (1.0 + 0.1 * 0.1 + 0.0 * 0.0);
		ikeda->x_new = 1.0 + ikeda->u
			* (0.1 * cos(ikeda->t) - 0.0 * sin(ikeda->t));
		ikeda->y_new = ikeda->u * (0.1 * sin(ikeda->t) + 0.0 * cos(ikeda->t));
		ikeda->pixel_x = ikeda->width / 2 + ikeda->x_new * ikeda->width / 5;
		ikeda->pixel_y = ikeda->height / 2 + ikeda->y_new * ikeda->height / 5;
		if (ikeda->pixel_x >= 0 && ikeda->pixel_x < ikeda->width
			&& ikeda->pixel_y >= 0 && ikeda->pixel_y < ikeda->height)
			my_mlx_pixel_put(ikeda, ikeda->pixel_x,
				ikeda->pixel_y, ikeda->color * i);
		i++;
	}
}
