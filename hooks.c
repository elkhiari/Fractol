#include "fractol.h"

int	mouse_down(int button, int x, int y, t_var *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.14;
	else if (button == 5)
		data->zoom /= 1.14;
	mlx_clear_window(data->mlx, data->mlx_wind);
    if (data->id == 0)
        make_mandelbrot(data);
	else if (data->id == 1)
        make_julia(data);
    return (0);
}

int     close_window(t_var *data)
{
    mlx_destroy_window(data->mlx,data->mlx_wind);
    exit(0);
}

int key_press(int keycode, t_var *data)
{
    printf("key = %d\n",keycode);
    if (keycode == 53)
        close_window(data);
    if (keycode == 32)
        data->enable_z *= -1 ;
    if (keycode == 8)
        data->new_color += 1;
    if (keycode == 124)
        data->off_x += 0.1 / data->zoom;
    if (keycode == 123)
        data->off_x -= 0.1 / data->zoom;
    if (keycode == 126)
        data->off_y -= 0.1 / data->zoom;
    if (keycode == 125)
        data->off_y += 0.1 / data->zoom;
    if (keycode == 15)
        {
            data->off_x = 0;
            data->off_y = 0;
            data->zoom = 4.0 / WIDTH;
        }
    mlx_clear_window(data->mlx, data->mlx_wind);
    if(data->id == 0)
        make_mandelbrot(data);
    if(data->id == 1)
        make_julia(data);
    return (0);
}

int mouse_point(int x, int y, t_var *data)
{
    if (data->enable_z == 1  && data->id == 1)
    {
        data->const_real = (x - WIDTH / 2) * data->zoom;
        data->const_img = (y - HEIGHT / 2) * data->zoom;
        mlx_clear_window(data->mlx,data->mlx_wind);
        make_julia(data);
    }
    return (0);
}

void    ft_hooks(t_var *data)
{
    mlx_mouse_hook(data->mlx_wind, mouse_down, data);
	mlx_hook(data->mlx_wind, 17, 0, close_window, data);
	mlx_hook(data->mlx_wind, 2, 0, key_press, data);
    mlx_hook(data->mlx_wind, 6, 0, mouse_point, data);
}