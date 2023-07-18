/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:22 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/18 14:38:32 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WITH  800
# define HEIGHT  800

typedef struct s_var
{
	void	*mlx;
	void	*mlx_wind;
	void	*mlx_img;
	int		bits_per_pixel;
	int		line_lenght;
	int		endiand;
	char	*addr;
}	t_var;

void	my_mlx_pixel_put(t_var *data, int x, int y, int color);

#endif