/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristianamarcu <cristianamarcu@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:35:58 by RAMON             #+#    #+#             */
/*   Updated: 2021/11/20 20:09:07 by cristianama      ###   ########.fr       */
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
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

typedef struct	s_mlx {
	void		*mlx;
	void		*win;
	t_fractal	*fractal;
}	t_mlx;

typedef struct	s_complex
{
	double	r;
	double	i;
}	t_complex;

#endif