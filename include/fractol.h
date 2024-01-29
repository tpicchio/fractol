/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:51:28 by tpicchio          #+#    #+#             */
/*   Updated: 2024/01/29 10:06:28 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define DIM			 500

# define BLACK           0x000000
# define WHITE           0xFFFFFF
# define YELLOW          0xFFFF00
# define GREEN           0x00FF00
# define SPRING_GREEN    0x00FF7F
# define CYAN            0x00FFFF
# define MAGENTA         0xFF00FF
# define ORANGE          0xFFA500
# define ORANGE_RED      0xFF4500
# define RED             0xFF0000
# define BLUE            0x0000FF

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_conn;
	void	*mlx_win;
	t_img	img;
	double	escaped;
	int		max_iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		init;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void		ft_fractal_init(t_fractal *fractal);
void		ft_data_init(t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal, int color);
void		ft_render_burningship(t_fractal *fractal, int flag);

double		ft_map(double unscaled_num, double new_min,
				double new_max, double old_max);
int			ft_color(int flag);
int			ft_valid_num(char *s);
void		ft_tutorial(void);

int			ft_key_handle(int keycode, t_fractal *fractal);
int			ft_mouse_handle(int button, int x, int y, t_fractal *fractal);
int			ft_close(t_fractal *fractal);

#endif
