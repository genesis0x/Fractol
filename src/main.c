/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:21:41 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/26 20:15:30 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	check(&data, ac, av);
	register_events(&data, 0);
	register_mouse_hook(&data);
	mlx_loop(data.mlx);
	while (1);
}
