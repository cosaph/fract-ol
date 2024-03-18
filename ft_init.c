/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:30:04 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/18 16:23:48 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if (argc != 1)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			mandelbrot_param(&fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "julia", 5)) // ft_strlen ????
			julia_param(&fractal, argv[1], ft_atof(argv[2]), ft_atof(argv[3]));
		else if (!ft_strncmp(argv[1], "ideka", 5))
			ikeda_param(&fractal, "ideka");
		else
		{
			ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}	
		fractal.mlx = mlx_init();
		fractal.win = mlx_new_window(fractal.mlx, fractal.width,
				fractal.height, fractal.name);
		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
		fractalsetup(&fractal);
		//mlx_key_hook(fractal.win, key_hook, &fractal); //TODO
		//mlx_mouse_hook(fractal.win, mouse_hook, &fractal); //TODO
		//mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal); //TODO
		mlx_loop(fractal.mlx);
	}
	else
		malloc_error();
	return (0);
}