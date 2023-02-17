/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:19:56 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/17 10:08:01 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int get_color(int max_iter, int iter) 
{
    if (iter == max_iter)
        return 0x000000; // Black for points in the set
    else 
	{
        double t = (double)iter / (double)max_iter; // Interpolation factor
        int r = (int)(9 * (1 - t) * t * t * t * 255);
        int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
        return (r << 16) | (g << 8) | b; // Combine color components
    }
}

void	julia(t_data *data)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			x;
	int			y;

	c = (t_complex){.re = 0.355, .im = 0.355};
	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			z.re  = x * 4.0 / (W * data->zoom) - 2.0 / data->zoom + data->x_off;
			z.im = (y - H / 2.0) * 4.0 / (W * data->zoom) + data->y_off;
			iter = calculate((t_complex){.re = 0.355,.im = 0.355}, z, data->max_iter);
			paint_pxl(&data->canvas, x, y, get_color(data->max_iter, iter));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img, 0, 0);
}


void	mandelbrot(t_data *data)
{
	t_complex	c;
	int			iter;
	int			x;
	int			y;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			c.re = x * 4.0 / (W * data->zoom) - 2.0 / data->zoom + data->x_off;
			c.im = (y - H / 2.0) * 4.0 / (W * data->zoom) + data->y_off;
			iter = calculate(c, (t_complex){.re = 0, .im = 0}, data->max_iter);
			paint_pxl(&data->canvas, x , y, get_color(data->max_iter, iter));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img, 0, 0);
}
