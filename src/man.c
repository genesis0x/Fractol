/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:16:56 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/23 18:21:20 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	man(int i)
{
	if (!i)
		write(1, "Usage: ./fractol [madelbrot] | [julia] | [burnin_ship]\n",
				55);
	else
	{
		write(1, "write one of this sets: ", 24);
		write(1, "[mandelbrot] | [julia] | [burning_ship]\n", 40);
	}
	exit(1);
}
