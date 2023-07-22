/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:32:39 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/22 07:50:30 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_julia_wind(void)
{
	t_var	data;

	ft_wind_prot(&data);
	data.id = 1;
	data.zoom = 4.0 / WIDTH;
	data.new_color = 0;
	data.enable_z = 1;
	ft_hooks(&data);
	make_julia(&data);
	mlx_loop(data.mlx);
}

void	make_julia(t_var *data)
{
	int		x;
	int		y;
	double	z_img;
	double	z_real;
	int		iterations;

	ft_img_prot(data);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_real = (x - WIDTH / 2.0 + data->off_x) * data->zoom;
			z_img = (y - HEIGHT / 2.0 + data->off_y) * data->zoom;
			iterations = julia(z_real, z_img, data);
			put_pixel(iterations, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_wind, data->mlx_img, 0, 0);
}

int	julia(double z_real, double z_img, t_var *data)
{
	double	cn_real;
	double	cn_img;
	double	c_real;
	double	c_img;
	int		iterations;

	c_real = data->const_real;
	c_img = data->const_img;
	iterations = 1;
	while (iterations <= MAX_ITER && (z_real * z_real + z_img * z_img <= 4))
	{
		cn_real = z_real * z_real - z_img * z_img + c_real ;
		cn_img = 2 * z_real * z_img + c_img;
		z_real = cn_real;
		z_img = cn_img;
		iterations++;
	}
	return (iterations);
}
