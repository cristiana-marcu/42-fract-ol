/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:45:57 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/07 11:10:42 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *mlx, t_complex z, t_complex c)
{
	int		i;
	double	n;
	double	temp;

	i = 0;
	n = z.r * z.r + z.i * z.i;
	temp = 0;
	while (i < mlx->fractal->max_iter && n < 4)
	{
		temp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * temp + c.i;
		n = z.r * z.r + z.i * z.i;
		i++;
	}
	return (i);
}
