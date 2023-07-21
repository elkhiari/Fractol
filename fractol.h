/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:22 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/21 16:42:45 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH  800
# define HEIGHT  800
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
	double	const_real;
	double	const_img;
	int		enable_z;
	int		new_color;
	double	off_x;
	double	off_y;
	int		id;
	int		type;
}				t_var;

void	my_mlx_pixel_put(t_var *var, int x, int y, int color);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	put_Error(void);
void	make_julia_wind();
void	put_pixel(int iterations, int x, int y, t_var *data);
int		give_trgb (int t, int r, int g, int b);
int		mandelbrot(double Creal, double Cimg);
void	make_mandelbrot(t_var *data);
void    make_mandelbrot_wind();
int	julia(double z_real, double z_img, t_var *data);
void	make_julia(t_var *data);
void    make_julia_wind();
void 	ft_img_prot(t_var *data);
void    ft_wind_prot(t_var *data);
int		mouse_down(int button, int x, int y, t_var *data);
int		close_window(t_var *data);
int		key_press(int keycode, t_var *data);
void    ft_hooks(t_var *data);
int		mouse_point(int x, int y, t_var *data);

#endif