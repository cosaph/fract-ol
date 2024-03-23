/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:30:04 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 17:06:47 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	process_fractal(char *fractal_type, char *param1, char *param2)
{
	t_fractal	fractal;

	if (!ft_strncmp(fractal_type, "mandelbrot", 10))
		mandelbrot_param(&fractal, fractal_type);
	else if (!ft_strncmp(fractal_type, "julia", 5))
		julia_param(&fractal, fractal_type, atodbl(param1), atodbl(param2));
	else if (!ft_strncmp(fractal_type, "ideka", 5))
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
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17, 1L << 17, close_fractal, &fractal);
	mlx_loop(fractal.mlx);
}

int	main(int argc, char **argv)
{
	char	*param1;
	char	*param2;

	if (argc != 1)
	{
		if (argc >= 2)
		{
			param1 = NULL;
			param2 = NULL;
			if (argc >= 3)
				param1 = argv[2];
			if (argc >= 4)
				param2 = argv[3];
			process_fractal(argv[1], param1, param2);
		}
		else
		{
			ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else
		malloc_error();
	return (0);
}
