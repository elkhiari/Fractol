/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:07 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/22 07:54:24 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_img_prot(t_var *data)
{
	data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->mlx_img)
		exit(1);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel,
			&data->line_lenght, &data->endiand);
	if (!data->addr)
		exit(1);
}

void	ft_wind_prot(t_var *data)
{
	data->mlx = mlx_init();
	data->mlx_wind = mlx_new_window(data->mlx, WIDTH, HEIGHT, "");
}
