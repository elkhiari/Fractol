/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:32:39 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/21 15:50:45 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	make_julia_wind(void)
{
	t_var	data;

	ft_wind_prot(&data);
	data.id = 1;
	ft_hooks(&data);
	make_julia(&data);
	mlx_loop(data.mlx);
}

void	make_julia(t_var *data)
{
	int		x;
	int		y;
	double	c_img;
	double	c_real;
	int		iterations;

	ft_img_prot(data);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_real = (x - WIDTH / 2.0 + data->off_x) * data->zoom;
			c_img = (y - HEIGHT / 2.0 + data->off_y) * data->zoom;
			iterations = julia(c_real, c_img);
			put_pixel(iterations, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_wind, data->mlx_img, 0, 0);
}

int	julia(double c_real, double c_img)
{
	double	zn_real;
	double	zn_img;
	double	z_real;
	double	z_img;
	int		iterations;

	iterations = 1;
	while (iterations <= MAX_ITER && (z_real * z_real + z_img * z_img <= 4))
	{
		zn_real = z_real * z_real - z_img * z_img + c_real;
		zn_img = 2 * z_real * z_img + c_img;
		z_real = zn_real;
		z_img = zn_img;
		iterations++;
	}
	return (iterations);
}
