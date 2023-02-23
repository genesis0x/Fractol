/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:30:49 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/23 01:21:20 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	check(t_data *data, int ac, char **av)
{
	if (ac != 2)
	{
		man(0);
		exit(0);
	}
	if (!strcmp(av[1], "julia"))
	{
		data->set = 1;
		init(data);
		julia(data);
	}
	else if (!strcmp(av[1], "mandelbrot"))
	{
		data->set = 2;
		init(data);
		mandelbrot(data);
	}
	else if (!strcmp(av[1], "burning_ship"))
	{
		data->set = 3;
		init(data);
		burning_ship(data);
	}
	else
		man(1);
}
