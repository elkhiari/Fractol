/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:56:19 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/19 16:02:02 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    make_mandelbrot_wind(t_var *data)
{
        data->mlx = mlx_init();
		data->mlx_wind = mlx_new_window(data->mlx, WITH, HEIGHT, "mandelbrot");
		data->mlx_img = mlx_new_image(&data->mlx, WITH, HEIGHT);
		data->addr = mlx_get_data_addr(data->mlx, &data->bits_per_pixel,
				&data->line_lenght, &data->endiand);
		data->zoom = 3.0 / WITH;
		mlx_loop(data->mlx);
}