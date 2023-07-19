/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:22 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/19 15:55:37 by oelkhiar         ###   ########.fr       */
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
# define ITER 80.0

typedef struct s_var
{
	void	*mlx;
	void	*mlx_wind;
	void	*mlx_img;
	int		bits_per_pixel;
	int		line_lenght;
	int		endiand;
	char	*addr;
	double	zoom;
	double	j_constant_real;
	double	j_constant_imag;
	int		enable_zoom;
	int		color_changed;
	double	off_x;
	double	off_y;
}	t_var;

void	my_mlx_pixel_put(t_var *data, int x, int y, int color);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	put_Error(void);
void	make_julia_wind(t_var *data);
void	make_mandelbrot_wind(t_var *data);

#endif