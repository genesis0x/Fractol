/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:20:19 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/17 08:42:25 by hahadiou         ###   ########.fr       */
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

	i = -1;
	while (++i < max_iter)
	{
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		tmp = (t_complex){z.re * z.re - z.im * z.im + c.re, 2 * z.re
			* z.im + c.im};
		z = tmp;
	}
	return (i);
}
