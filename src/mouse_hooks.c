/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:26:51 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/19 23:30:59 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_hook(int key, int x, int y, t_data *data)
{
	if (key == ON_MOUSEDOWN)
	{
		data->zoom *= 2.0;
		data->x_off -= (4.0 / (W * data->zoom) - 8.0 / (W * data->zoom)) * (x
				- W / 2);
		data->y_off -= (4.0 / (W * data->zoom) - 8.0 / (W * data->zoom)) * (y
				- H / 2);
		set_fractal(data);
	}
	if (key == ON_MOUSEUP)
	{
		data->zoom /= 2.0;
		data->x_off -= (4.0 / (W * data->zoom) - 8.0 / (W * data->zoom)) * (x
				- W / 2);
		data->y_off -= (4.0 / (W * data->zoom) - 8.0 / (W * data->zoom)) * (y
				- H / 2);
		set_fractal(data);
	}
	return (0);
}

void	register_mouse_hook(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_hook, data);
}
