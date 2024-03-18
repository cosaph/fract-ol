/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_koch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:32:06 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/18 15:49:51 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"



void ikedaAttractor(t_fractal *ikeda) {
    int i = 0;
    double x = 0.1;
    double y = 0.0;

    while (i < ikeda->iterations) {
        double t = 0.4 - 6.0 / (1.0 + x * x + y * y);
        double x_new = 1.0 + ikeda->u * (x * cos(t) - y * sin(t));
        double y_new = ikeda->u * (x * sin(t) + y * cos(t));

        x = x_new;
        y = y_new;

        int pixel_x = ikeda->width / 2 + x * ikeda->width / 5;
        int pixel_y = ikeda->height / 2 + y * ikeda->height / 5;

        if (pixel_x >= 0 && pixel_x < ikeda->width && pixel_y >= 0 && pixel_y < ikeda->height) {
            my_mlx_pixel_put(ikeda, pixel_x, pixel_y, ikeda->color * i);
        }

        i++;
    }
}
void ikeda_param(t_fractal *fractal, char *name) {
    fractal->width = 800;
    fractal->height = 800;
    fractal->u = 0.9;
    fractal->iterations = 10000000;
    fractal->color = PSYCHEDELIC_WARM;
    fractal->name = name;
}