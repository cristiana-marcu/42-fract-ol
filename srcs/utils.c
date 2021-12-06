/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:47:32 by cmarcu            #+#    #+#             */
/*   Updated: 2021/12/06 22:42:59 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	print_error(char *message)
{
	printf("Error - %s \n", message);
	exit(-1);
}

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
