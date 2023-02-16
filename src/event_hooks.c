/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:23 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/16 23:45:45 by hahadiou         ###   ########.fr       */
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
	if (key == 126)
	{
		data->zoom *= 2.0;
		julia(data);
		//mandelbrot(data);
	}
	if (key == 125)
	{
		data->zoom /= 2.0;
		julia(data);
		//mandelbrot(data);
	}
	return (0);
}

int	mouse_hook(int key, t_data *data)
{
	printf("key: %d\n", key);
	if (key == 5)
	{
		data->zoom *= 2.0;
		//julia(data);
		mandelbrot(data);
	}
	if (key == 4)
	{
		data->zoom /= 2.0;
		//julia(data);
		mandelbrot(data);
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
