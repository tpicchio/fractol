/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:13 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:31 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	s1_len;

	start = 0;
	if (!s1 || s1 == NULL)
		return (NULL);
	if (!(set) || set == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	while (s1[start] && chr_in_set(s1[start], set))
		start++;
	while (s1_len > start && chr_in_set(s1[s1_len - 1], set))
		s1_len--;
	return (ft_substr(s1, start, s1_len - start));
}

/*Parameters
	s1: The string to be trimmed.
	set: The reference set of characters to trim.

Return value
	The trimmed string.
	NULL if the allocation fails.

External functs
	malloc

Description
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.*/