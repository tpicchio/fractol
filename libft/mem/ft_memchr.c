/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:13 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:34:48 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	uc;

	buff = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*buff == uc)
			return ((void *)buff);
		buff++;
	}
	return (NULL);
}

/*DESCRIPTION
       The memchr() function scans the initial n  bytes  of  the  memory
       area pointed to by s for the first instance of c.  Both c and the
       bytes of the memory area pointed to by s are interpreted  as  un‐
       signed char.

RETURN VALUE
       The memchr() and memrchr() functions  return  a  pointer  to  the
       matching  byte  or  NULL  if  the character does not occur in the
       given memory area.*/