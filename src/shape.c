/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:56 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/23 01:33:25 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia(t_data *data)
{
	t_complex	z;
	int			iter;
	int			x;
	int			y;
	int hue;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			z.re = x * 4.0 / (W * data->zoom) - 2.0 / data->zoom + data->x_off;
			z.im = (y - H / 2.0) * 4.0 / (W * data->zoom) + data->y_off;
			iter = calculate(data->c, z, data->max_iter, 0);
			if (iter == data->max_iter)
				paint_pxl(&data->canvas, x, y, 0x000000);
			else
			{
				hue = iter * iter % 360;
				paint_pxl(&data->canvas, x, y, hsv_to_rgb(hue, 1, 1, 0));
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img, 0, 0);
}

void	mandelbrot(t_data *data)
{
	t_complex		c;
	int				iter;
	unsigned int	x;
	unsigned int	y;
	int hue;

	y = -1;
	while (++y < data->canvas.h)
	{
		x = -1;
		while (++x < data->canvas.w)
		{
			c.re = x * 4.0 / (W * data->zoom) - 2.0 / data->zoom + data->x_off;
			c.im = (y - H / 2.0) * 4.0 / (W * data->zoom) + data->y_off;
			iter = calculate(c, (t_complex){.re = 0, .im = 0}, \
					data->max_iter, 0);
			if (iter == data->max_iter)
				paint_pxl(&data->canvas, x, y, 0x000000);
			else
			{
				hue = iter * iter % 360;
				data->color = hsv_to_rgb(hue, 1, 1, 0);
				paint_pxl(&data->canvas, x, y, data->color);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img, 0, 0);
}

void	burning_ship(t_data *data)
{
	t_complex		c;
	int				iter;
	unsigned int	x;
	unsigned int	y;
	int hue;

	y = -1;
	while (++y < data->canvas.h)
	{
		x = -1;
		while (++x < data->canvas.w)
		{
			c.re = x * 4.0 / (W * data->zoom) - 2.0 / data->zoom + data->x_off;
			c.im = (y - H / 2.0) * 4.0 / (W * data->zoom) + data->y_off;
			iter = calculate(c, (t_complex){.re = 0, .im = 0}, data->max_iter,
					1);
			if (iter == data->max_iter)
				paint_pxl(&data->canvas, x, y, 0x000000);
			else
			{
				hue = iter * iter % 360;
				data->color = hsv_to_rgb(hue, 1, 1, 0);
				paint_pxl(&data->canvas, x, y, data->color);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img, 0, 0);
}
