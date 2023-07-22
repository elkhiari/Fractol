/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:14:19 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/22 08:20:51 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	put_pixel(int iterations, int x, int y, t_var *data)
{
	int	color;

	color = (iterations * 255 / MAX_ITER);
	if (iterations >= MAX_ITER)
		my_mlx_pixel_put(data, x, y, 0);
	else
	{
		if (data->new_color % 2 == 0)
			my_mlx_pixel_put(data, x, y,
				give_trgb(0, color + 20, color - 10, color + 10));
		else
			my_mlx_pixel_put(data, x, y,
				give_trgb(0, color - 10, color + 20, color - 10));
	}
}

int	give_trgb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}
