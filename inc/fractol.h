/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:25:35 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/16 23:05:35 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define W 1200
# define H 750
# define TITLE "Fractol"

# define K_ESC 53
# define K_A 0
# define K_S 1
# define K_D 2
# define MAX_ITER 256
enum
{
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data		t_data;
typedef struct s_main		t_main;
typedef struct s_canvas		t_canvas;
typedef struct s_point		t_point;
typedef struct s_complex	t_complex;

struct						s_complex
{
	double					real;
	double					imag;
};

struct						s_point
{
	double					x;
	double					y;
};

struct						s_canvas
{
	t_point					p;
	unsigned int			w;
	unsigned int			h;
	void					*img;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
};

struct						s_main
{
	t_canvas				canvas;
	int						x_pos;
	void					(*draw_on_screen)(t_data *);
};

struct						s_data
{
	void					*mlx;
	void					*win;
	t_main					main;
	double					ps; // pixel_size
	double					zoom;
};

int							calculate(t_complex c, t_complex z, int max_iter);
void						mandelbrot(t_data *data);
void						julia(t_data *data);
void						init(t_data *data);
void						init_canvas(void *mlx, t_canvas *c);
int							key_handler(int key, t_data *data);
int							close_window(t_data *data);
void						register_events(t_data *data);
void						paint_pxl(t_canvas *canvas, int x, int y,
								int color);

#endif
