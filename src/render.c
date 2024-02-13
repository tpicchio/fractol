/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:53:31 by tpicchio          #+#    #+#             */
/*   Updated: 2024/01/17 11:51:56 by tpicchio         ###   ########.fr       */
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
/*
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
}*/


#include <pthread.h>

#define NUM_THREADS 20 // Modifica il numero di thread in base al numero di core della tua CPU o alle prestazioni ottimali

typedef struct {
    t_fractal *fractal;
    int flag;
    int start_row;
    int end_row;
} ThreadData;

void *render_thread(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int x, y;
    int color = ft_color(data->flag);
    
    for (y = data->start_row; y < data->end_row; y++) {
        for (x = 0; x < DIM; x++) {
            ft_handle_pixel(data->fractal, x, y, color);
        }
    }
    
    pthread_exit(NULL);
}

void ft_fractal_render(t_fractal *fractal, int flag) {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int row_per_thread = DIM / NUM_THREADS;
    int remainder = DIM % NUM_THREADS;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].fractal = fractal;
        thread_data[i].flag = flag;
		flag = 0;
        thread_data[i].start_row = i * row_per_thread;
        thread_data[i].end_row = (i + 1) * row_per_thread;
        if (i == NUM_THREADS - 1) {
            thread_data[i].end_row += remainder; // Assicura che l'ultimo thread gestisca eventuali righe residue
        }
        pthread_create(&threads[i], NULL, render_thread, (void *)&thread_data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    mlx_put_image_to_window(fractal->mlx_conn, fractal->mlx_win, fractal->img.img_ptr, 0, 0);
}
