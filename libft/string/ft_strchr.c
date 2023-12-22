/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:23 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:20 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*DESCRIPTION
       The  strchr()  function returns a pointer to the first occurrence of
       the character c in the string s.

       Here "character" means "byte"; these functions do not work with wide
       or multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched
       character  or  NULL  if the character is not found.  The terminating
       null byte is considered part of the string, so that if c  is  speci‐
       fied as '\0', these functions return a pointer to the terminator.*/