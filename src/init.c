/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:42:25 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/17 09:05:16 by hahadiou         ###   ########.fr       */
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
	printf("init.\n");
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, W, H, TITLE);
	if (!data->win)
	{
		free(data->mlx);
		exit(1);
	}
	data->main.canvas.w = W;
	data->main.canvas.h = H;
	data->zoom = 1.0;
	data->x_off = 0;
	data->y_off = 0;
	data->max_iter = 50;
	init_canvas(data->mlx, &data->main.canvas);
	printf("end init.\n");
}
