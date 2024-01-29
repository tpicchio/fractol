/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:52:01 by tpicchio          #+#    #+#             */
/*   Updated: 2024/01/29 10:09:52 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_malloc_error(void)
{
	perror("Malloc failure");
	exit(EXIT_FAILURE);
}

void	ft_data_init(t_fractal *fractal)
{
	fractal->escaped = 4.0;
	fractal->max_iter = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	if (fractal->init == 0)
	{
		fractal->julia_x = -0.8;
		fractal->julia_y = 0.156;
		fractal->init = 1;
	}
}

static void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, ft_key_handle, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, ft_mouse_handle,
		fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask,
		ft_close, fractal);
}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx_conn = mlx_init();
	if (fractal->mlx_conn == NULL)
		ft_malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_conn,
			DIM, DIM, "fract'ol  by  tpicchio");
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_conn);
		free(fractal->mlx_conn);
		ft_malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_conn, DIM, DIM);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_conn, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_conn);
		free(fractal->mlx_conn);
		ft_malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	ft_tutorial();
	ft_events_init(fractal);
	ft_data_init(fractal);
}
