/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:42 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:24 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	buf_left;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (src_len + size);
	buf_left = size - dest_len;
	if (buf_left > src_len)
		buf_left = src_len;
	else
		buf_left -= 1;
	ft_memcpy(dest + dest_len, src, buf_left);
	dest[dest_len + buf_left] = '\0';
	return (dest_len + src_len);
}

/*DESCRIPTION
        The strlcat() function appends the NUL-terminated string src to the end
        of dst. It will append at most size - strlen(dst) - 1 bytes,
        NUL-terminating the result.
        Note that a byte for the NUL terminator should be included in size.
        Also note that strlcat() only operates on true C strings, which means
        src and dst must be NUL-terminated.

RETURN VALUE
        The strlcat() function returns the initial length of dst plus the
        length of src. This is the total length of the string it tried to
        create.
        Note that if strlcat() traverses size characters without finding a NUL,
        the length is considered to be size and dst will not be NUL-terminated.
        This prevents potential security problems.*/