/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:56 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/17 04:55:56 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia(t_data *data)
{
	t_complex	c;
	int			iter;
	int			x;
	int			y;

	c = (t_complex){.real = 0.355, .imag = 0.355};
	for (y = 0; y < H; y++)
	{
		for (x = 0; x < W; x++)
		{
			t_complex z = {(x - W / 2.0) * 4.0 / (data->zoom * W),
							(y - H / 2.0) * 4.0 / (data->zoom * W)};
			iter = calculate(c, z, data->max_iter);
			paint_pxl(&data->main.canvas, x, y, (iter * iter) * 2);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
}

void	mandelbrot(t_data *data)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			x;
	int			y;

	z = (t_complex){.real = 0, .imag = 0};
	for (y = 0; y < H; y++)
	{
		for (x = 0; x < W; x++)
		{
			c.real = ((x - W / 2.0) * 4.0 / W) / data->zoom + ((data->zoom
						- 1.0) / data->zoom);
			c.imag = ((y - H / 2.0) * 4.0 / W) / data->zoom + ((data->zoom
						- 1.0) / data->zoom);
			iter = calculate(c, z, data->max_iter);
			paint_pxl(&data->main.canvas, x + data->x_off, y + data->y_off, (iter * iter) * 2);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
}
