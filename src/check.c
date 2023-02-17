/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:30:49 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/17 09:35:05 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	check(t_data *data, int ac, char **av)
{
	if (ac != 2)
	{
		printf("Bad Usage\n");
		exit(0);
	}
	if (!strcmp(av[1], "julia"))
	{
		data->set = 1;
		init(data);
		julia(data);
	}
	else if (!strcmp(av[1], "mandlebrot"))
	{
		data->set = 2;
		init(data);
		mandelbrot(data);
	}
	else
	{
		printf("Chof ach katktb Ya W9\n");
		exit(1);
	}
}
