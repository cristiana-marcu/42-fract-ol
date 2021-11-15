/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristianamarcu <cristianamarcu@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:29:10 by cristianama       #+#    #+#             */
/*   Updated: 2021/11/15 19:52:07 by cristianama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 700, 700, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);

	int width = 100;
	int height;
	while (width > 0)
	{
		height = 100;
		while (height > 0)
		{
			my_mlx_pixel_put(&img, width, height, 0x00FF0000);
			height--;
		}
		width--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
	mlx_loop(mlx);
}