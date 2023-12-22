/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:09 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:30 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			last = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

/*DESCRIPTION
       The strrchr() function returns a pointer to the last  occurrence  of
       the character c in the string s.

       Here "character" means "byte"; these functions do not work with wide
       or multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched
       character  or  NULL  if the character is not found.  The terminating
       null byte is considered part of the string, so that if c  is  speci‐
       fied as '\0', these functions return a pointer to the terminator.*/