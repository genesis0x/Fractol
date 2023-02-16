/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:21:41 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/16 23:44:15 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(void)
{
	t_data	data;

	init(&data);
	//mandelbrot(&data);
	julia(&data);
	register_events(&data);
	mlx_loop(data.mlx);
}
