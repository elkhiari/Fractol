/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:22 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/20 17:16:25 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH  500
# define HEIGHT  500
# define MAX_ITER 80


typedef struct s_var
{
	void	*mlx;
	void	*mlx_wind;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endiand;
	double	zoom;
	double	j_constant_real;
	double	j_constant_imag;
	int		enable_zoom;
	int		color_changed;
	double	off_x;
	double	off_y;
}				t_var;

void	my_mlx_pixel_put(t_var *var, int x, int y, int color);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	put_Error(void);
void	make_julia_wind();
void	put_pixel(int iterations, int x, int y, t_var *data);
int		give_trgb (int t, int r, int g, int b);
int		mandelbort(double Creal, double Cimg);
void	make_mandelbort(t_var *data);
void	ft_hooks(t_var *data);
void    make_mandelbrot_wind();
int mouse_hook(int button, int x, int y, t_var *data);

#endif