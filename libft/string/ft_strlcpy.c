/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:46 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:25 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (src_len >= size)
		len = size - 1;
	else
		len = src_len;
	if (size > 0)
	{
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (src_len);
}

/*DESCRIPTION
        The strlcpy() function copies up to size - 1 characters from the
        NUL-terminated string src to dst, NUL-terminating the result.
        Note that a byte for the NUL terminator should be included in size.
        Also note that strlcpy() only operates on true C strings, which means
        src must be NUL-terminated.

RETURN VALUE
        The strlcpy() function returns the total length of the string it tried
        to create, which means the length of src.*/