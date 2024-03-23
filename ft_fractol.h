/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottet <ccottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:51:58 by ccottet           #+#    #+#             */
/*   Updated: 2024/03/23 17:33:10 by ccottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "mlx/mlx.h"
# include "ft_printf/includes/ft_printf.h"

# define ERROR_MESSAGE "Please enter mandelbrot or julia <value_1> <value_2>"

# define PSYCHEDELIC_WARM    0x470712

# define ESC 53
# define LEFT 123
# define UP 126
# define RIGHT 124
# define DOWN 125
# define R 15
# define Z 6
# define PLUS 69
# define MINUS 78

//** struc
typedef struct s_complex
{
	double	x;
	double	y;
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
	double		mouse_x;
	double		mouse_y;
	double		u;
	double		t;
	double		x_new;
	double		y_new;
	int			pixel_x;
	int			pixel_y;
}	t_fractal;

//** strings_utils

int			ft_strncmp( const char *s1, const char *s2, size_t n );
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
double		atodbl(char *s);

//** init 
void		fractal_init(t_fractal *fractal);
int			freeall(t_fractal *fractal);
void		fractalsetup(t_fractal *fractal);
void		malloc_error(void);

//** linear interpolation (ft_math_utils)
t_complex	mappoint(t_fractal *julia, double x, double y);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//** render
void		fractal_render(t_fractal *fractal);
void		mandelbrotset(t_fractal *mandel);
void		minimandel(int x, int y, t_fractal *mandel);
int			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);

//** params
void		mandelbrot_param(t_fractal *fractal, char *name);
void		julia_param(t_fractal *fractal, char *name, double cx, double cy);

//** Julia 
void		juliaset(t_fractal *julia);

//** Ideka 
t_complex	mappoint_ideka(t_fractal *ikeda, int x, int y);
void		ikedaattractor(t_fractal *ikeda);
void		ikeda_param(t_fractal *fractal, char *name);

//** Zoom 
void		ft_zoom(double x, double y, t_fractal *fractal);
void		ft_dezoom(double x, double y, t_fractal *fractal);
int			mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int			key_hook(int keycode, t_fractal *fractal, double cx, double cy);
int			close_fractal(t_fractal	*fractal);

#endif
