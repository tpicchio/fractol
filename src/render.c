/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:53:31 by tpicchio          #+#    #+#             */
/*   Updated: 2024/02/14 13:35:19 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_complex(t_fractal *fractal, t_complex *c, t_complex *z)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
}

static void	ft_handle_pixel(t_fractal *fractal, int x, int y, int col)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;
	int			color;

	i = -1;
	z.x = (((x * (4.0 / DIM)) - 2) * fractal->zoom) + fractal->shift_x;
	z.y = (((y * (-4.0 / DIM)) + 2) * fractal->zoom) + fractal->shift_y;
	ft_set_complex(fractal, &c, &z);
	while (++i < fractal->max_iter)
	{
		tmp = z.x;
		z.x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2 * tmp * z.y) + c.y;
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ((i * 0x1051E) << 16) | (i * 0x105) << 8 | (col / 250) << 4;
			tmp = (x * (fractal->img.bpp / 8)) + (y * fractal->img.line_len);
			*(unsigned int *)(fractal->img.pixels_ptr + (int)tmp) = color;
			return ;
		}
	}
	tmp = (x * (fractal->img.bpp / 8)) + (y * fractal->img.line_len);
	*(unsigned int *)(fractal->img.pixels_ptr + (int)tmp) = col;
}

void	ft_fractal_render(t_fractal *fractal, int flag)
{
	int	x;
	int	y;
	int	color;

	color = ft_color(flag);
	flag = 0;
	y = -1;
	while (++y < DIM)
	{
		x = -1;
		while (++x < DIM)
		{
			ft_handle_pixel(fractal, x, y, color);
		}
	}
	mlx_put_image_to_window(fractal->mlx_conn, fractal->mlx_win,
		fractal->img.img_ptr, 0, 0);
}
