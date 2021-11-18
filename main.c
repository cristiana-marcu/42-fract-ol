/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristianamarcu <cristianamarcu@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:29:10 by cristianama       #+#    #+#             */
/*   Updated: 2021/11/18 21:48:06 by cristianama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

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

void render_next_frame(t_data *img) //Futuro parámetro "t_mlx *mlx" para hacer aquí el put_image_to_window
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, create_trgb(0, 187, 0, 47));
			x++;
		}
		y++;
	}
}

t_mlx	*init()
{
	t_mlx	*mlx;
	
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	return (mlx);
}

int	main(void)
{
	t_mlx	*mlx;
	t_data	img;

	mlx = init();
	img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
				
	render_next_frame(&img);
	//TODO next: una animación que con mlx_loop_hook pase por todos los colores.
	//Bitwise operands, aprende de una vez
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_key_hook(mlx->win, hook_keydown, mlx->mlx);
	mlx_loop(mlx->mlx);
}