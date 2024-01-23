/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:26:02 by tpicchio          #+#    #+#             */
/*   Updated: 2024/01/17 13:52:00 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_complex(t_complex *c, t_complex *z)
{
	c->x = z->x;
	c->y = z->y;
}

static void	ft_handle_burningship_pixel(t_fractal *fractal, int x, int y,
	int col)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;
	int			color;

	i = -1;
	z.x = (((x * (4.0 / DIM)) - 2) * fractal->zoom) + fractal->shift_x;
	z.y = (((y * (-4.0 / DIM)) + 2) * fractal->zoom) + fractal->shift_y;
	ft_set_complex(&c, &z);
	while (++i < fractal->max_iter)
	{
		tmp = z.x;
		z.x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = fabs(2 * tmp * z.y) + c.y;
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ((i * 0x1051E) << 16) | (i * 0x105) << 8 | (col / 250) << 4;
			tmp = x * fractal->img.bpp / 8 + (DIM - y) * fractal->img.line_len;
			*(unsigned int *)(fractal->img.pixels_ptr + (int)tmp) = color;
			return ;
		}
	}
	tmp = (x * (fractal->img.bpp / 8)) + ((DIM - y) * fractal->img.line_len);
	*(unsigned int *)(fractal->img.pixels_ptr + (int)tmp) = col;
}

void	ft_render_burningship(t_fractal *fractal, int flag)
{
	int	x;
	int	y;
	int	color;

	color = ft_color(flag);
	flag = 0;
	x = -1;
	while (++x < DIM)
	{
		y = -1;
		while (++y < DIM)
			ft_handle_burningship_pixel(fractal, x, y, color);
	}
	mlx_put_image_to_window(fractal->mlx_conn, fractal->mlx_win,
		fractal->img.img_ptr, 0, 0);
}
