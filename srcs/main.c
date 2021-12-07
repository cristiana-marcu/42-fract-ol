/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:29:10 by cristianama       #+#    #+#             */
/*   Updated: 2021/12/07 16:29:39 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init(char **argv)
{
	t_data	*mlx;

	mlx = (t_data *)malloc(sizeof(t_data));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		print_error("Failed initializing mlx");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	if (!mlx->win)
		print_error("Failed creating window");
	if (!match_fractal(mlx, argv[1]))
		print_error("Wrong argument. Type [Mandelbrot] [Julia]");
	init_image(mlx);
	mlx->zoom = 300;
	mlx->offset_x = WIN_WIDTH / 8;
	mlx->offset_y = WIN_HEIGHT / 50;
	return (mlx);
}

void	init_image(t_data *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_length,
			&mlx->endian);
}

int	main(int argc, char **argv)
{
	t_data	*mlx;

	if (argc != 2 && ft_strncmp(argv[1], "Julia", 5) != 0)
		print_error("Wrong number of arguments. Type [Mandelbrot] [Julia]");
	mlx = init(argv);
	if (argc == 3)
		init_julias(argv[2], mlx);
	fractol(mlx);
	mlx_key_hook(mlx->win, hook_keydown, mlx);
	mlx_hook(mlx->win, 17, 0, close, fractol);
	mlx_mouse_hook(mlx->win, hook_mouse_scroll, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

//Places where I malloc: init function, match_fractal function
