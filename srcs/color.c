/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:51:19 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/06 14:45:10 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	calculate_color(int i, t_data *mlx)
{
	int t;
	int r;
	int g;
	int b;

	t = 0;
	r = (65 * i) / mlx->fractal->max_iter;
	g = (95 * i) / mlx->fractal->max_iter;
	b = (185 * i) / mlx->fractal->max_iter;
	return (create_trgb(t, r, g, b));
}
