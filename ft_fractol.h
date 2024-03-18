/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:51:58 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/18 16:26:57 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
#  define FT_FRACTOL_H

# include <stdio.h> //TODO debugging
# include <stdlib.h> //malloc free
# include <unistd.h> // write
# include <math.h>

#include "mlx/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot\" or \n\t\" ./fractol julia <value_1> <value_2>\n \""

// Basic Colors
#define BLACK       0x000000
#define WHITE       0xFFFFFF

// Psychedelic Colors
#define PSYCHEDELIC_WARM    0x470712



typedef struct s_complex
{
	double x;
	double y;
}			t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_ptr;	
	int		bpp;
	int		endian;
	int		line_len;

}				t_img;

typedef struct s_fractal {
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
	double		u;
}				t_fractal;		

//** utils
int		ft_strncmp( const char *s1, const char *s2, size_t n );
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
double	ft_atof(char *str);
static int	skip_space_sign(char *str, int *is_neg);
int	ft_isdigit(int c);
int	ft_isspace(char c);

//** init 

void	fractal_init(t_fractal *fractal);
int	freeall(t_fractal *fractal);
void	fractalsetup(t_fractal *fractal);
void	malloc_error(void);

//** linear interpolation (ft_math_utils)
t_complex	mappoint(t_fractal *julia, double x, double y);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//** render
void fractal_render(t_fractal *fractal);
void	mandelbrotset(t_fractal *mandel);
void	minimandel(int x, int y, t_fractal *mandel);
int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);

//** params

void	mandelbrot_param(t_fractal *fractal, char *name);
void	julia_param(t_fractal *fractal, char *name, double cx, double cy);

//** Julia 

void	juliaset(t_fractal *julia);

//** Ideka 


t_complex	mappoint_ideka(t_fractal *ikeda, int x, int y);
void ikedaAttractor(t_fractal *ikeda);
void ikeda_param(t_fractal *fractal, char *name);

#endif
