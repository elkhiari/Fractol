/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:32:39 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/19 15:43:14 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    make_julia_wind(t_var *data)
{
        data->mlx = mlx_init();
		data->mlx_wind = mlx_new_window(data->mlx, WITH, HEIGHT, "julia");
		data->mlx_img = mlx_new_image(&data->mlx, WITH, HEIGHT);
		data->addr = mlx_get_data_addr(data->mlx, &data->bits_per_pixel,
				&data->line_lenght, &data->endiand);
		mlx_loop(data->mlx);
}