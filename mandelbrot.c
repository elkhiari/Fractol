/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:56:19 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/20 17:21:42 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_mandelbrot_wind()
{
	t_var	data;
	
	data.mlx = mlx_init();
	data.mlx_wind = mlx_new_window(data.mlx, WIDTH, HEIGHT, "mandelbrot");
	data.zoom = 4.0 / WIDTH;
	make_mandelbort(&data);
	mlx_loop(data.mlx);
}

void	make_mandelbort(t_var *data)
{
	int		x;
	int		y;
	double	c_img;
	double	c_real;
	int iterations;
	data->mlx_img = mlx_new_image(&data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel,
			&data->line_lenght, &data->endiand);
	ft_hooks(data);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_real = (x - WIDTH / 2 + data->off_x) * data->zoom;
			c_img = (y - HEIGHT / 2 + data->off_y) * data->zoom;
			iterations = mandelbort(c_real,c_img);
			put_pixel(iterations,x,y,data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_wind, data->mlx_img, 0, 0);
}

int	mandelbort(double c_real, double c_img)
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


void ft_hooks(t_var *data)
{
	mlx_mouse_hook(data->mlx_wind, mouse_hook, data);
}

int mouse_hook(int button, int x, int y, t_var *data)
{
	(void)data;
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.05;
	else if(button == 5)
		data->zoom /= 1.14;
	make_mandelbort(data);
	return (0);
}