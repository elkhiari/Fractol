/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:15 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/21 17:16:37 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal (char *string)
{
	if (ft_strncmp(string,"Julia",5) && ft_strlen(string) == 5)
		make_julia_wind();
	else if(ft_strncmp(string,"Mandelbrot",10) && ft_strlen(string) == 10)
		make_mandelbrot_wind();
	else if(ft_strncmp(string,"Burnningship",12) && ft_strlen(string) == 12)
		make_burnningship_wind();
	else 
		put_Error();
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		check_fractal(av[1]);
	}
	else
		put_Error();
}
