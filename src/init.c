/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:42:25 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/19 23:01:30 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_canvas(void *mlx, t_canvas *c)
{
	c->img = mlx_new_image(mlx, c->w, c->h);
	if (!c->img)
		exit(1);
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_len, &c->endian);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, W, H, TITLE);
	if (!data->win)
	{
		free(data->mlx);
		exit(1);
	}
	data->canvas.w = W;
	data->canvas.h = H;
	data->zoom = 1.0;
	data->x_off = 0;
	data->y_off = 0;
	data->max_iter = 50;
	data->c.re = 0.355;
	data->c.im = 0.355;
	init_canvas(data->mlx, &data->canvas);
}
