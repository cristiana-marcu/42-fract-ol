/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:14:22 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/08 10:33:47 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_data *mlx, t_complex z)
{
	double	aux;
	int		i;

	i = 0;
	aux = 0;
	while (i < mlx->fractal->max_iter && (z.r * z.r + z.i * z.i < 4))
	{
		aux = z.r;
		z.r = aux * aux - z.i * z.i + mlx->julia.r;
		z.i = 2 * z.i * aux + mlx->julia.i;
		i++;
	}
	return (i);
}

void	init_julias(char *argv, t_data *mlx)
{
	if (!ft_strncmp(argv, "1", 1))
		mlx->julia = (t_complex){.r = -0.506667, .i = 0.520000};
	else if (!ft_strncmp(argv, "2", 1))
		mlx->julia = (t_complex){.r = 0.403333, .i = 0.273333};
	else if (!ft_strncmp(argv, "3", 1))
		mlx->julia = (t_complex){.r = 0.386667, .i = 0.103333};
	else if (!ft_strncmp(argv, "4", 1))
		mlx->julia = (t_complex){.r = -0.203333, .i = -0.696667};
	else if (!ft_strncmp(argv, "5", 1))
		mlx->julia = (t_complex){.r = 0.371504, .i = -0.153893 };
	else
		print_error("Wrong arguments. Type [Julia 1] [Julia 2] ... [Julia 5]");
}
