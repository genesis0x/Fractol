/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:23 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/23 01:26:01 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	reset(t_data *data)
{
	data->x_off = 0;
	data->y_off = 0;
	data->zoom = 1.0;
	data->max_iter = 150;
	set_fractal(data);
}

int	key_handler(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == WK || key == S)
	{
		data->max_iter += 5 * (key == WK) - 5 * (key == S);
		set_fractal(data);
	}
	if (key == L || key == R)
	{
		data->x_off -= (0.2 / data->zoom) * (key == R) - 0.1 / data->zoom;
		set_fractal(data);
	}
	if (key == U || key == D)
	{
		data->y_off += (0.2 / data->zoom) * (key == U) - 0.1 / data->zoom;
		set_fractal(data);
	}
	if (key == RES)
		reset(data);
	return (0);
}

int	loop_hook(t_data *data)
{
	hsv_to_rgb(0, 1, 1, 1);
	set_fractal(data);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	register_events(t_data *data, int b)
{
	if (b)
		mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_hook(data->win, ON_KEYDOWN, 0, key_handler, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, close_window, data);
}
