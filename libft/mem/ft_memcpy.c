/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:23 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:34:50 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*buff1;
	const unsigned char	*buff2;

	if (!(dest) && !(src))
		return (dest);
	buff1 = (unsigned char *)dest;
	buff2 = (const unsigned char *)src;
	if (dest < src && src < dest + n)
		return (ft_memmove(dest, src, n));
	while (n--)
		*buff1++ = *buff2++;
	return (dest);
}

/*DESCRIPTION
       The  memcpy()  function  copies  n bytes from memory area src to
       memory area dest.  The memory areas must not overlap.  Use  mem‐
       move(3) if the memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.*/