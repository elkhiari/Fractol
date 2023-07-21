/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnningship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:56:19 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/21 16:04:43 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_burnningship_wind(void)
{
	t_var	data;

	ft_wind_prot(&data);
	data.zoom = 4.0 / WIDTH;
	data.new_color = 0;
	data.id = 2;
	ft_hooks(&data);
	make_burnningship(&data);
	mlx_loop(data.mlx);
}

void	make_burnningship(t_var *data)
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
			iterations = burnningship(c_real, c_img);
			put_pixel(iterations, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_wind, data->mlx_img, 0, 0);
}

int	burnningship(double c_real, double c_img)
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
		zn_img = fabs( 2 * z_real * z_img) + c_img;
		z_real = zn_real;
		z_img = zn_img;
		iterations++;
	}
	return (iterations);
}
