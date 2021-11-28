/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristianamarcu <cristianamarcu@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:29:10 by cristianama       #+#    #+#             */
/*   Updated: 2021/11/28 17:00:41 by cristianama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int hook_keydown(int key) //Futuro parámetro "t_mlx *mlx" para hacer zoom con teclas
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int mandelbrot(t_mlx *mlx, t_complex z, t_complex c)
{
	int		i;
	double	n;
	double	temp;

	i = 0; //Possible to initialize it at -1 if I get short on lines and in the loop ++i
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

int calculate_color(int i, t_mlx *mlx) {
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

void fill_pixel(int x, int y, t_data *img, t_mlx *mlx)
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
		my_mlx_pixel_put(img, x, y, create_trgb(0, 187, 0, 47));
	else //TODO calcular color en función de i
		my_mlx_pixel_put(img, x, y, calculate_color(i, mlx));
}

void fractol(t_data *img, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			fill_pixel(x, y, img, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (n && s1[a] != '\0' && s1[a] == s2[a])
	{
		a++;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return ((int)(unsigned char)(s1[a]) - (int)(unsigned char)(s2[a]));
}


int	match_fractal(t_mlx *mlx, char *argv)
{
	mlx->fractal = (t_fractal*)malloc(sizeof(t_fractal));
	if (!ft_strncmp(argv, "Mandelbrot", 10))
	{
		mlx->fractal->name = MANDELBROT; //TODO: segfault here without line 74
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

void	print_error(char *message)
{
	printf("Error - %s \n", message);
	exit(1);
}

t_mlx	*init(char *argv)
{
	t_mlx	*mlx;
	//char	*title;

	//title = ft_strjoin("Fract'ol - ", argv);
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
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
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_data	img;

	if (argc != 2)
		print_error("Wrong number of arguments");
	mlx = init(argv[1]);
	//TODO: init_img para las dos líneas siguientes.
	img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	
	
	fractol(&img, mlx);
	//TODO next: una animación que con mlx_loop_hook pase por todos los colores.
	//Bitwise operands, aprende de una vez
	
	mlx_key_hook(mlx->win, hook_keydown, mlx->mlx);
	mlx_loop(mlx->mlx);
}

//Places where I malloc: init function, match_fractal function