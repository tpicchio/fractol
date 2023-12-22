/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:27 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:34:51 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*DESCRIPTION
       The  memmove()  function  copies n bytes from memory area src to
       memory area dest.  The memory areas may overlap:  copying  takes
       place  as though the bytes in src are first copied into a tempo‐
       rary array that does not overlap src or dest, and the bytes  are
       then copied from the temporary array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.*/