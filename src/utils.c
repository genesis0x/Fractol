/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:20:19 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/16 18:47:16 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	paint_pxl(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
	*(unsigned int *)dst = color;
}

int	calculate(t_complex c, t_complex z, int max_iter)
{
	int			i;
	t_complex	tmp;

	for (i = 0; i < max_iter; i++)
	{
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
		tmp = (t_complex){z.real * z.real - z.imag * z.imag + c.real, 2 * z.real
			* z.imag + c.imag};
		z = tmp;
	}
	return (i);
}
