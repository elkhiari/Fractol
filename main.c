/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:15 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/22 08:24:24 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_error(void)
{
	write(1, "---------------------\n", 22);
	write(1, "available arguments\n", 21);
	write(1, "\t->mandelbrot\n", 14);
	write(1, "\t->julia\n", 9);
	write(1, "\t->burnningship\n", 16);
	write(1, "---------------------\n", 22);
	exit(1);
}

void	check_fractal(char *string)
{
	if (ft_strcmp (string, "Julia") && ft_strlen(string) == 5)
		make_julia_wind();
	else if (ft_strcmp (string, "Burnningship") && ft_strlen(string) == 12)
		make_burnningship_wind();
	else if (ft_strcmp (string, "Mandelbrot") && ft_strlen(string) == 10)
		make_mandelbrot_wind();
	else
		put_error();
}

int	main(int ac, char **av)
{
	if (ac == 2)
		check_fractal(av[1]);
	else
		put_error();
}
