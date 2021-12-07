/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:51:19 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/07 00:44:40 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	calculate_color(int i, t_data *mlx)
{
	int	t;
	int	r;
	int	g;
	int	b;
	double	aux;

	t = 0;
	aux = (double)i / mlx->fractal->max_iter;
	r = (int)9 * (1 - aux) * pow(aux, 3) * 255;
	g = (int)15 * pow((1 - aux), 2) * pow(aux, 2) * 255;
	b = (int)8.5 * pow((1 - aux), 3) * aux * 255;
	return (create_trgb(t, r, g, b));
}
