/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:29:10 by cristianama       #+#    #+#             */
/*   Updated: 2021/12/06 14:53:12 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(int x, int y, t_data *mlx)
{
	t_complex	z;
	t_complex	c;
	int			i;

	//TODO find a better way to convert pixel to complex
	c.r = (double)x / 400 + mlx->fractal->viewport.xmin;
	c.i = (double)y / 400 + mlx->fractal->viewport.ymin;
	z = (t_complex) {.r = 0, .i = 0};
	i = 0;
	if (mlx->fractal->name == MANDELBROT)
		i = mandelbrot(mlx, z, c);
	if (i == mlx->fractal->max_iter)
		my_mlx_pixel_put(mlx, x, y, create_trgb(0, 187, 0, 47));
	else //TODO calcular color en función de i
		my_mlx_pixel_put(mlx, x, y, calculate_color(i, mlx));
}

t_data	*init(char *argv)
{
	t_data	*mlx;
	//char	*title;

	//title = ft_strjoin("Fract'ol - ", argv);
	mlx = (t_data*)malloc(sizeof(t_data));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		print_error("Failed initializing mlx");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol - ");
	if (!mlx->win)
		print_error("Failed creating window");
	if (!match_fractal(mlx, argv))
		print_error("Wrong argument. Please type 'Mandelbrot'");
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img,
				&mlx->bits_per_pixel, &mlx->line_length,
				&mlx->endian);
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
	mlx_loop(mlx->mlx);
	return (0);
}

//Places where I malloc: init function, match_fractal function
