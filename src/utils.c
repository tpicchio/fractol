/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:59:01 by tpicchio          #+#    #+#             */
/*   Updated: 2024/01/23 12:28:34 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double unscaled_num, double new_min,
	double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

int	ft_color(int flag)
{
	static int	i;

	if (flag == 1)
		i++;
	if (i == 1)
		return (BLACK);
	else if (i == 2)
		return (MAGENTA);
	else if (i == 3)
		return (ORANGE_RED);
	else if (i == 4)
		return (ORANGE);
	else if (i == 5)
		return (GREEN);
	else if (i == 6)
		return (YELLOW);
	else if (i == 7)
		return (SPRING_GREEN);
	else if (i == 8)
		return (CYAN);
	else
	{
		i = 0;
		return (WHITE);
	}
}

int	ft_valid_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '0' && s[i + 1] != '.' && s[i + 1] != '\0')
		i = -1;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	if (!s[i] && i != -1)
		return (1);
	else if ((s[i] == '.' && i > 0))
		i++;
	else
		i = -1;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0' || s[i - 1] == '.' || i < 0)
	{
		ft_printf(2, "\nEnter a valid number.\n\n");
		exit(EXIT_FAILURE);
	}
	else
		return (1);
	return (0);
}

void	ft_tutorial(void)
{
	ft_printf(1, "\n\n______________________________________\n");
	ft_printf(1, "|                                    |\n");
	ft_printf(1, "|        Welcome to fract'ol         |\n");
	ft_printf(1, "|                                    |\n");
	ft_printf(1, "| Instructions:                      |\n");
	ft_printf(1, "| -Zoom with mouse wheel             |\n");
	ft_printf(1, "| -Move with arrows                  |\n");
	ft_printf(1, "| -Shift color range with c          |\n");
	ft_printf(1, "| -Change fractal with:              |\n");
	ft_printf(1, "|     -b (Burning ship)              |\n");
	ft_printf(1, "|     -m (Mandelbrot)                |\n");
	ft_printf(1, "|     -j (Julia, def: -0.8 0.156)    |\n");
	ft_printf(1, "| -Change Julia constant with wasd   |\n");
	ft_printf(1, "| -Change details with + and -       |\n");
	ft_printf(1, "| -Reset the image with r            |\n");
	ft_printf(1, "| -Exit with ESC                     |\n");
	ft_printf(1, "|____________________________________|\n\n");
}
