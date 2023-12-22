/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:28 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:21 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*DESCRIPTION
       The strdup() function returns a pointer to a new string which is a
       duplicate of the string s.  Memory for the new string is  obtained
       with malloc(3), and can be freed with free(3).

RETURN VALUE
       On success, the strdup() function returns a pointer to the  dupli‐
       cated  string.   It returns NULL if insufficient memory was avail‐
       able, with errno set to indicate the cause of the error.

ERRORS
       ENOMEM Insufficient memory available to allocate duplicate string.*/