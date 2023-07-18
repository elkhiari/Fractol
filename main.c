/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:15 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/18 14:45:50 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_var	data;

	if (ac == 2)
	{
		data.mlx = mlx_init();
		data.mlx_wind = mlx_new_window(data.mlx, WITH, HEIGHT, av[1]);
		data.mlx_img = mlx_new_image(&data.mlx, WITH, HEIGHT);
		data.addr = mlx_get_data_addr(data.mlx, &data.bits_per_pixel,
				&data.line_lenght, &data.endiand);
		printf("%s", av[1]);
		mlx_loop(data.mlx);
	}
	else
		write(1, "ERROR", 5);
}
