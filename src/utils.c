/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:20:19 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/26 20:40:38 by hahadiou         ###   ########.fr       */
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
			tmp = (t_complex){fabs(z.re * z.re - z.im * z.im + c.re),
								fabs(2 * z.re * z.im + c.im)};
		else
			tmp = (t_complex){(z.re * z.re - z.im * z.im + c.re),
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

int	hsv_to_rgb(float h, float s, float v, int shift)
{
	float		c;
	float		x;
	float		m;
	static int	shift_color;
	int			red;
	int			green;
	int			blue;
	
	c = v * s; // c = 1;
	x = c * (1.0 - fabs(fmod((double)h / 60.0, 2.0) - 1.0));
	m = v - c; // m = 0;
	float r, g, b;
	if (shift)
	{
		shift_color += 4;
		return (0);
	}
	if (h >= 0 && h < 60)
	{
		r = c;
		g = x;
		b = 0;
	}
	else if (h >= 60 && h < 120)
	{
		r = x;
		g = c;
		b = 0;
	}
	else if (h >= 120 && h < 180)
	{
		r = 0;
		g = c;
		b = x;
	}
	else if (h >= 180 && h < 240)
	{
		r = 0;
		g = x;
		b = c;
	}
	else if (h >= 240 && h < 300)
	{
		r = x;
		g = 0;
		b = c;
	}
	else
	{
		r = c;
		g = 0;
		b = x;
	}
	red = (int)((r) * 255) + shift_color;
	green = (int)((g) * 255) + shift_color;
	blue = (int)((b) * 255) + shift_color;
	return ((red << 16) | (green << 8) | blue);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
