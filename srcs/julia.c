/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:14:22 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/06 19:35:28 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_data *mlx, t_complex z)
{
	double aux;
	int i;

	i = 0;
	aux = 0;
	while(i < mlx->fractal->max_iter && (z.r * z.r + z.i * z.i < 4))
	{
		aux = z.r;
		z.r = aux * aux - z.i * z.i + mlx->julia.r;
		z.i = 2 * z.i * aux + mlx->julia.i;
		i++;
	}
	return (i);
}
