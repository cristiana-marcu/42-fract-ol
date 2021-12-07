/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:44:53 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/07 15:02:20 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_keydown(int key, t_data *mlx) //Futuro parámetro "t_mlx *mlx" para hacer zoom con teclas
{
	if (key == K_ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		exit(EXIT_SUCCESS);
	}
	else if (key == K_ARR_UP || key == K_ARR_LEFT || key == K_ARR_DOWN
		|| key == K_ARR_RIGHT)
		move(key, mlx);
	return (0);
}

void	move(int key, t_data *mlx)
{
	t_complex	aux;

	aux.r = fabs(mlx->fractal->viewport.xmax - mlx->fractal->viewport.xmin);
	aux.i = fabs(mlx->fractal->viewport.ymax - mlx->fractal->viewport.ymin);
	if (key == K_ARR_UP)
		mlx->offset_y += aux.i * 20;
	else if (key == K_ARR_DOWN)
		mlx->offset_y -= aux.i * 20;
	else if (key == K_ARR_LEFT)
		mlx->offset_x += aux.i * 20;
	else if (key == K_ARR_RIGHT)
		mlx->offset_x -= aux.i * 20;
	fractol(mlx);
}
