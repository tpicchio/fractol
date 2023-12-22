/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:00:24 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/22 17:07:31 by tpicchio         ###   ########.fr       */
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

int	ft_key_handle(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		ft_close(fractal);
	if (keycode == XK_Left)
		fractal->shift_x -= 0.1 * fractal->zoom;
	else if (keycode == XK_Right)
		fractal->shift_x += 0.1 * fractal->zoom;
	else if (keycode == XK_Up)
		fractal->shift_y -= 0.1 * fractal->zoom;
	else if (keycode == XK_Down)
		fractal->shift_y += 0.1 * fractal->zoom;
	else if (keycode == XK_KP_Add || keycode == XK_plus)
		fractal->max_iter += 10;
	else if (keycode == XK_KP_Subtract || keycode == XK_minus)
		fractal->max_iter -= 10;
	ft_fractal_render(fractal);
	return (0);
}


int	ft_mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	//zoom in and out based on mouse position
	if (button == 5)
	{
		fractal->zoom *= 1.1;
		fractal->shift_x -= (ft_map(x, -2, +2, WIDTH) * fractal->zoom) / 10;
		fractal->shift_y -= (ft_map(y, +2, -2, HEIGHT) * fractal->zoom) / 10;
	}
	else if (button == 4)
	{
		fractal->zoom /= 1.1;
		fractal->shift_x += (ft_map(x, -2, +2, WIDTH) * fractal->zoom) / 10;
		fractal->shift_y += (ft_map(y, +2, -2, HEIGHT) * fractal->zoom) / 10;
	}
	else if (button == 1)
		fractal->is_dragging = 1;
	else if (button == ButtonRelease)
		fractal->is_dragging = 0;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_mouse_move(int x, int y, t_fractal *fractal)
{
	if (fractal->is_dragging)
	{
		fractal->shift_x += (ft_map(x, -2, +2, WIDTH) * fractal->zoom) / 10;
		fractal->shift_y += (ft_map(y, +2, -2, HEIGHT) * fractal->zoom) / 10;
		ft_fractal_render(fractal);
	}
	return (0);
}
