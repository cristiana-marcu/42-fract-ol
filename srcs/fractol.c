/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:48:18 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/06 14:51:18 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	match_fractal(t_data *mlx, char *argv)
{
	mlx->fractal = (t_fractal*)malloc(sizeof(t_fractal));
	if (!ft_strncmp(argv, "Mandelbrot", 10))
	{
		mlx->fractal->name = MANDELBROT;
		mlx->fractal->viewport.xmax = 1.0;
		mlx->fractal->viewport.ymax = 1.0;
		mlx->fractal->viewport.xmin = -2.0;
		mlx->fractal->viewport.ymin = -1.0;
		mlx->fractal->max_iter = 80;
	}
	else
		return (0);
	return (1);
}

void fractol(t_data *mlx)
{
	int	x;
	int	y;

	y = 0;
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
