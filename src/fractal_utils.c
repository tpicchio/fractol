/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:59:01 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/22 16:04:59 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double unscaled_num, double new_min,
	double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}
