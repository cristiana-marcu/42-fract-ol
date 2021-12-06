/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:29:10 by cristianama       #+#    #+#             */
/*   Updated: 2021/12/06 19:27:20 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init(char *argv)
{
	t_data	*mlx;
	mlx = (t_data*)malloc(sizeof(t_data));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		print_error("Failed initializing mlx");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!mlx->win)
		print_error("Failed creating window");
	if (!match_fractal(mlx, argv))
		print_error("Wrong argument. Available fractals - [Mandelbrot] [Julia]");
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img,
				&mlx->bits_per_pixel, &mlx->line_length,
				&mlx->endian);
	mlx->zoom = 200;
	mlx->offset_x = 0;
	mlx->offset_y = 0;
	mlx->julia = (t_complex) {.r = -0.506667, .i = 0.520000 };
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_data	*mlx;

	if (argc != 2) //TODO cambiar a mayor de 2 para las opciones de julia
		print_error("Wrong number of arguments. Available fractals - [Mandelbrot] [Julia]");
	mlx = init(argv[1]);

	fractol(mlx);

	mlx_key_hook(mlx->win, hook_keydown, mlx);
	mlx_mouse_hook(mlx->win, hook_mouse_scroll, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

//Places where I malloc: init function, match_fractal function
