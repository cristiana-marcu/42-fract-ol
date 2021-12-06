/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:48:18 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/06 22:37:31 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	match_fractal(t_data *mlx, char *argv)
{
	mlx->fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!ft_strncmp(argv, "Mandelbrot", 10))
	{
		mlx->fractal->name = MANDELBROT;
		mlx->fractal->viewport.xmax = 1.0;
		mlx->fractal->viewport.ymax = 1.0;
		mlx->fractal->viewport.xmin = -2.0;
		mlx->fractal->viewport.ymin = -1.0;
		mlx->fractal->max_iter = 80;
	}
	else if (!ft_strncmp(argv, "Julia", 10))
	{
		mlx->fractal->name = JULIA;
		mlx->fractal->viewport.xmax = 1.0;
		mlx->fractal->viewport.ymax = 1.0;
		mlx->fractal->viewport.xmin = -2.0;
		mlx->fractal->viewport.ymin = -1.0;
		mlx->fractal->max_iter = 300;
	}
	else
		return (0);
	return (1);
}

void	fractol(t_data *mlx)
{
	int	x;
	int	y;

	y = 0;
	//Intento de que el zoom siga la posiciçon del ratón
	//mlx->fractal->viewport.xmin = ((mlx->offset_x + (WIN_WIDTH >> 1)) / (mlx->zoom / 2)) / -2;
	//mlx->fractal->viewport.ymin = ((mlx->offset_y + (WIN_HEIGHT >> 1)) / (mlx->zoom / 2)) / -2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			fill_pixel(x, y, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	fill_pixel(int x, int y, t_data *mlx)
{
	t_complex	z;
	t_complex	c;
	int			i;

	//TODO find a better way to convert pixel to complex
	c.r = (double)x / mlx->zoom + mlx->fractal->viewport.xmin;
	c.i = (double)y / mlx->zoom + mlx->fractal->viewport.ymin;
	z = (t_complex){.r = 0, .i = 0};
	i = 0;
	if (mlx->fractal->name == MANDELBROT)
		i = mandelbrot(mlx, z, c);
	else if (mlx->fractal->name == JULIA)
		i = julia(mlx, c);
	if (i == mlx->fractal->max_iter)
		my_mlx_pixel_put(mlx, x, y, create_trgb(0, 187, 0, 47));
	else //TODO calcular color en función de i
		my_mlx_pixel_put(mlx, x, y, calculate_color(i, mlx));
}
