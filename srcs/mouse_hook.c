/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:56:42 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/07 19:05:48 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mouse_scroll(int button, int x, int y, t_data *mlx)
{
	double		scale;
	t_complex	mouse;

	scale = 0;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT
		&& (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN))
	{
		mouse.r = (double)x / (WIN_WIDTH / mlx->fractal->viewport.xmax
				- mlx->fractal->viewport.xmin);
		mouse.i = (double)x / (WIN_HEIGHT / mlx->fractal->viewport.ymax
				- mlx->fractal->viewport.ymin);
		if (button == MOUSE_SCROLL_UP)
			scale = 1.10;
		else if (button == MOUSE_SCROLL_DOWN)
			scale = 0.8;
		mlx->offset_x = round(mlx->offset_x + ((WIN_WIDTH >> 1) - x) * scale);
		mlx->offset_y = round(mlx->offset_y + ((WIN_HEIGHT >> 1) - y) * scale);
		mlx->zoom *= scale;
		fractol(mlx);
	}
	return (1);
}
