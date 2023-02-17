/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:23 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/17 05:13:50 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	key_handler(int key, t_data *data)
{
	printf("key: %d\n", key);
	if (key == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == 34)
	{
		data->max_iter += 50;
		init_canvas(data->mlx, &data->main.canvas);
		mandelbrot(data);
	}
	if (key == 123)
	{
		data->x_off -= 10;
		init_canvas(data->mlx, &data->main.canvas);
		mandelbrot(data);
	}
	if (key == 124)
	{
		data->x_off += 10;
		init_canvas(data->mlx, &data->main.canvas);
		mandelbrot(data);
	}
	// if (key == 125)
	// {
	// 	data->y_off += 10;
	// 	init_canvas(data->mlx, &data->main.canvas);
	// 	//julia(data);
	// 	mandelbrot(data);
	// }
	// if (key == 126)
	// {		
	// 	data->y_off -= 10;
	// 	init_canvas(data->mlx, &data->main.canvas);
	// 	//julia(data);
	// 	mandelbrot(data);
	// }
	return (0);
}

int mouse_hook(int key, int x, int y, t_data *data)
{
	//(void)data;
	printf("Mouse key %d was pressed at (%d,%d)\n", key, x, y);
    if (key == 1)
    {
		data->zoom *= 2;
		//init_canvas(data->mlx, &data->main.canvas);
		//init(data);
		//mandelbrot(data);
    }
    return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	register_events(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_hook, &data);
	mlx_hook(data->win, ON_KEYDOWN, 0, key_handler, data);
	mlx_hook(data->win, ON_DESTROY, 0, close_window, data);
}
