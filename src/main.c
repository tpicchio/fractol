/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:51:53 by tpicchio          #+#    #+#             */
/*   Updated: 2024/02/14 13:12:31 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6))
		|| (ac == 2 && !ft_strncmp(av[1], "burningship", 12)))
	{
		fractal.name = av[1];
		fractal.init = 0;
		if (av[1][0] == 'j' && ft_valid_num(av[2]) && ft_valid_num(av[3]))
		{
			fractal.julia_x = ft_atodbl(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
			fractal.init = 1;
		}
		ft_fractal_init(&fractal);
		if (av[1][0] == 'm' || av[1][0] == 'j')
			ft_fractal_render(&fractal, 1);
		else
			ft_render_burningship(&fractal, 1);
		mlx_loop(fractal.mlx_conn);
	}
	else
		ft_printf(2, "\nAvailable fractal:\n-mandelbrot\n-julia [num][num]%s",
			"\n-burningship\n\n");
	return (0);
}
