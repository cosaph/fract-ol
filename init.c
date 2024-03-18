/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:21:19 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/18 15:44:09 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "mlx/mlx.h"

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "ideka", 5))
		ikedaAttractor(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	exit(0);
}

void	fractal_init(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "ideka", 5))
		ikedaAttractor(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}