/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:12 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:15 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispositive(int c)
{
	if (c == '+')
		return (1);
	return (-1);
}

static intmax_t	ft_mount_num(const char *nptr, int *error)
{
	intmax_t	i;
	size_t		z;
	size_t		sign;

	i = 0;
	z = 0;
	sign = 1;
	while (ft_isspace(nptr[z]))
		z++;
	if (nptr[z] == '\0')
	{
		*error = 1;
		return (0);
	}
	if (nptr[z] == '-' || nptr[z] == '+')
	{
		sign = ft_ispositive(nptr[z]);
		z++;
	}
	while (nptr[z] && nptr[z] >= '0' && nptr[z] <= '9')
	{
		i = i * 10 + nptr[z] - '0';
		z++;
	}
	return (i * sign);
}

int	ft_atoi(const char *nptr, int *error)
{
	intmax_t	num;

	*error = 0;
	num = ft_mount_num(nptr, error);
	if (*error == 1)
		return (0);
	if (num < INT_MIN || num > INT_MAX)
	{
		*error = 1;
		return (0);
	}
	return ((int)num);
}

/*DESCRIPTION
       The  atoi()  function  converts  the  initial  portion of the
       nptring pointed to by nptr to int.
       (...)except that atoi() does not detect errors.

RETURN VALUE
       The converted value.*/