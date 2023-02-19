/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:20:19 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/19 23:33:42 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	paint_pxl(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
	*(unsigned int *)dst = color;
}

int	calculate(t_complex c, t_complex z, int max_iter, int b)
{
	int			i;
	t_complex	tmp;

	i = -1;
	while (++i < max_iter)
	{
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		if (b)
			tmp = (t_complex){fabs(z.re * z.re - z.im * z.im + c.re), \
				fabs(2 * z.re * z.im + c.im)};
		else
			tmp = (t_complex){(z.re * z.re - z.im * z.im + c.re), \
				(2 * z.re * z.im + c.im)};
		z = tmp;
	}
	return (i);
}

void	set_fractal(t_data *data)
{
	if (data->set == 1)
		julia(data);
	if (data->set == 2)
		mandelbrot(data);
	if (data->set == 3)
		burning_ship(data);
}

int	get_color(t_data *data, int iter, int shift)
{
	int			r;
	int			g;
	int			b;
	double		t;
	static int	shift_color;

	if (shift)
	{
		shift_color += 8;
		return (0);
	}
	if (iter == data->max_iter)
		return (0x000000);
	else
	{
		t = (double)iter / (double)data->max_iter;
		r = (int)(9 * (1 - t) * t * t * t * 255) + shift_color;
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255) + shift_color;
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + shift_color;
		return ((r << 16) | (g << 8) | b);
	}
}
