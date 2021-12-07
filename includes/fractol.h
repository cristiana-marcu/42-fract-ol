/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:35:58 by RAMON             #+#    #+#             */
/*   Updated: 2021/12/07 09:22:51 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

//Keys
# define K_ESC			53
# define K_TAB			9
# define K_ARR_LEFT		123
# define K_ARR_UP		126
# define K_ARR_RIGHT	124
# define K_ARR_DOWN		125

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

//Window
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

enum	e_fractal{MANDELBROT, JULIA};

//Structures
typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_viewport
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

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_fractal	*fractal;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	int			offset_x;
	int			offset_y;
	t_complex	julia;
}	t_data;

t_data	*init(char **argv);
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
int		hook_mouse_scroll(int button, int x, int y, t_data *mlx);
double	interpolate(double start, double end, double interpolation);
void	recalculate_viewport(t_complex mouse, t_data *mlx, double scale);
int		julia(t_data *mlx, t_complex z);
void	move(int key, t_data *mlx);
void	init_julias(char *argv, t_data *mlx);
void	init_image(t_data *mlx);
int		close(void *param);

#endif
