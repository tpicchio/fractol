/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:04 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:29 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;

	if (!(*little))
		return ((char *)big);
	little_length = ft_strlen(little);
	if (little_length > len)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && (i + little_length) <= len)
	{
		if (ft_strncmp(big + i, little, little_length) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi‐
     nated string little in the string big, where not more than len charac‐
     ters are searched.  Characters that appear after a ‘\0’ character are
     not searched.  Since the strnstr() function is a FreeBSD specific API,
     it should only be used when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs
     nowhere in big, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of little is returned.*/