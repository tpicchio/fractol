/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:00:24 by tpicchio          #+#    #+#             */
/*   Updated: 2024/01/29 10:09:13 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_conn, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_conn, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_conn);
	free(fractal->mlx_conn);
	exit(EXIT_SUCCESS);
}

static void	ft_arrow_detail_handle(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Left && fractal->shift_x > -3)
		fractal->shift_x -= 0.1 * fractal->zoom;
	else if (keycode == XK_Right && fractal->shift_x < 2)
		fractal->shift_x += 0.1 * fractal->zoom;
	else if (keycode == XK_Up && fractal->shift_y < 3)
		fractal->shift_y += 0.1 * fractal->zoom;
	else if (keycode == XK_Down && fractal->shift_y > -3)
		fractal->shift_y -= 0.1 * fractal->zoom;
	else if (keycode == XK_KP_Add && fractal->max_iter < 100)
		fractal->max_iter += 10;
	else if (keycode == XK_KP_Subtract && fractal->max_iter > 10)
		fractal->max_iter -= 10;
}

static int	ft_letter_handle(int keycode, t_fractal *fractal)
{
	int	flag;

	flag = 0;
	if (keycode == XK_c)
		return (1);
	else if (keycode == XK_b && fractal->name[0] != 'b')
	{
		fractal->name = "burningship";
		ft_data_init(fractal);
	}
	else if (keycode == XK_m && fractal->name[0] != 'm')
	{
		fractal->name = "mandelbrot";
		ft_data_init(fractal);
	}
	else if (keycode == XK_j && fractal->name[0] != 'j')
	{
		fractal->name = "julia";
		ft_data_init(fractal);
	}
	else if (keycode == XK_r)
		ft_data_init(fractal);
	return (flag);
}

int	ft_key_handle(int keycode, t_fractal *fractal)
{
	int	flag;

	flag = 0;
	if (keycode == XK_Escape)
		ft_close(fractal);
	if (keycode == XK_Left || keycode == XK_Right || keycode == XK_Up
		|| keycode == XK_Down || keycode == XK_KP_Add
		|| keycode == XK_KP_Subtract)
		ft_arrow_detail_handle(keycode, fractal);
	else if (keycode == XK_c || keycode == XK_b || keycode == XK_m
		|| keycode == XK_j || keycode == XK_r)
		flag = ft_letter_handle(keycode, fractal);
	else if (keycode == XK_w && fractal->name[0] == 'j')
		fractal->julia_y += 0.01;
	else if (keycode == XK_a && fractal->name[0] == 'j')
		fractal->julia_x -= 0.01;
	else if (keycode == XK_s && fractal->name[0] == 'j')
		fractal->julia_y -= 0.01;
	else if (keycode == XK_d && fractal->name[0] == 'j')
		fractal->julia_x += 0.01;
	if (fractal->name[0] == 'j' || fractal->name[0] == 'm')
		ft_fractal_render(fractal, flag);
	else
		ft_render_burningship(fractal, flag);
	return (0);
}

int	ft_mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5 && fractal->zoom < 2.000000)
	{
		fractal->zoom *= 1.1;
		fractal->shift_x -= (ft_map(x, -2, +2, DIM) * fractal->zoom) / 10;
		if (fractal->name[0] == 'j' || fractal->name[0] == 'm')
			fractal->shift_y -= (ft_map(y, +2, -2, DIM) * fractal->zoom) / 10;
		else
			fractal->shift_y += (ft_map(y, +2, -2, DIM) * fractal->zoom) / 10;
	}
	else if (button == 4 && fractal->zoom > 0.0000000000005)
	{
		fractal->zoom /= 1.1;
		fractal->shift_x += (ft_map(x, -2, +2, DIM) * fractal->zoom) / 10;
		if (fractal->name[0] == 'j' || fractal->name[0] == 'm')
			fractal->shift_y += (ft_map(y, +2, -2, DIM) * fractal->zoom) / 10;
		else
			fractal->shift_y -= (ft_map(y, +2, -2, DIM) * fractal->zoom) / 10;
	}
	if (fractal->name[0] == 'j' || fractal->name[0] == 'm')
		ft_fractal_render(fractal, 0);
	else
		ft_render_burningship(fractal, 0);
	return (0);
}
