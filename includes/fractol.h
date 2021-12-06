/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:35:58 by RAMON             #+#    #+#             */
/*   Updated: 2021/12/06 14:58:11 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

//Keys
# define K_ESC	53

//Window
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

enum	e_fractal{MANDELBROT, JULIA};

//Structures

typedef struct	s_viewport
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}	t_viewport;

typedef struct s_fractal
{
	enum e_fractal	name;
	t_viewport		viewport;
	int				max_iter;
}	t_fractal;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	t_fractal	*fractal;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct	s_complex
{
	double	r;
	double	i;
}	t_complex;

int		mandelbrot(t_data *mlx, t_complex z, t_complex c);
int		hook_keydown(int key, t_data *mlx);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_error(char *message);
int		match_fractal(t_data *mlx, char *argv);
void	fractol(t_data *mlx);
void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		calculate_color(int i, t_data *mlx);
void	fill_pixel(int x, int y, t_data *mlx);

#endif
