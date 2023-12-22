/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:53:31 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/22 16:10:51 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (x * (img->bpp / 8)) + (y * img->line_len);
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

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

static void	ft_handle_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;
	int			color;

	i = -1;
	z.x = (ft_map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (ft_map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	ft_set_complex(fractal, &c, &z);
	while (++i < fractal->max_iter)
	{
		tmp = z.x;
		z.x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2 * tmp * z.y) + c.y;
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped)
		{
			color = ft_map(i, BLACK, WHITE, fractal->max_iter);
			ft_put_pixel(&fractal->img, x, y, color);
			return ;
		}
	}
	ft_put_pixel(&fractal->img, x, y, NEON_ORANGE);
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_handle_pixel(fractal, x, y);
		}
	}
	mlx_put_image_to_window(fractal->mlx_conn, fractal->mlx_win,
		fractal->img.img_ptr, 0, 0);
}
