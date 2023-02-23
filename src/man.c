/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:16:56 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/23 01:22:41 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void    man(int i)
{
    if (!i)
        printf("Usage: ./fractol [mandelbrot] | [julia] | [burning_ship]");
    else
        printf("Please selecet one of this sets: [mandelbrot] | [julia] | [burning_ship]");
    exit(1);
}