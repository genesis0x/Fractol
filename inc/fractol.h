/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:25:35 by hahadiou          #+#    #+#             */
/*   Updated: 2023/02/26 20:34:45 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define W 1500
# define H 1000
# define TITLE "Fractol"
# define ESC 53
# define L 123
# define R 124
# define U 126
# define D 125
# define RES 15
# define WK 13
# define S 1
# define SHIFT_COLOR 1

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
typedef struct s_canvas		t_canvas;
typedef struct s_complex	t_complex;

struct						s_complex
{
	double					re;
	double					im;
};

struct						s_canvas
{
	unsigned int			w;
	unsigned int			h;
	void					*img;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
};

struct						s_data
{
	void					*mlx;
	void					*win;
	t_canvas				canvas;
	double					ps;
	double					zoom;
	double					x_off;
	double					y_off;
	int						max_iter;
	int						set;
	int						color;
	t_complex				c;
};

int							calculate(t_complex c, t_complex z, int max_iter,
								int b);
void						mandelbrot(t_data *data);
void						register_events(t_data *data, int b);
void						burning_ship(t_data *data);
void						julia(t_data *data);
void						init(t_data *data);
void						init_canvas(void *mlx, t_canvas *c);
int							key_handler(int key, t_data *data);
int							close_window(t_data *data);
void						paint_pxl(t_canvas *c, int x, int y, int color);
void						check(t_data *data, int ac, char **av);
void						set_fractal(t_data *data);
int							get_color(t_data *data, int iter, int shift);
int							mouse_hook(int key, int x, int y, t_data *data);
void						register_mouse_hook(t_data *data);
int hsv_to_rgb(float h, float s, float v, int shift);
void    man(int i);
int	ft_strcmp(char *s1, char *s2);

#endif
