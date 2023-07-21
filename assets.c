/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:19 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/20 17:00:47 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (x[i] && y[i] && x[i] == y[i] && i < n - 1)
		i++;
	return (x[i] - y[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	put_Error(void)
{
	write(1, "ERROR", 5);
	exit(1);
}

void	put_pixel(int iterations, int x, int y, t_var *data)
{
	int color;

	color = (iterations * 255 / MAX_ITER);
	if (iterations >= MAX_ITER)
		my_mlx_pixel_put(data,x,y,0);
	else
	{
		if(data->new_color % 2 == 0)
			my_mlx_pixel_put(data,x,y,give_trgb(0, color+20, color-10, color+10));
		else
			my_mlx_pixel_put(data,x,y,give_trgb(0, color-10, color+20, color-10));
	}
}

int give_trgb (int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}