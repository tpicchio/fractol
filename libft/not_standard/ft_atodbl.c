/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:49:07 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/22 16:00:34 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodbl(char *s)
{
	long	int_part;
	double	dec_part;
	int		sign;
	double	pow;

	int_part = 0;
	dec_part = 0.0;
	sign = 1;
	pow = 1.0;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s) && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (ft_isdigit(*s) && *s)
	{
		pow /= 10;
		dec_part = dec_part + (*s++ - '0') * pow;
	}
	return ((int_part + dec_part) * sign);
}
