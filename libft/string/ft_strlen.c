/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:51 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:26 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*DESCRIPTION
       The  strlen() function calculates the length of the string
       pointed to by  s,  excluding  the  terminating  null  byte
       ('\0').

RETURN VALUE
       The  strlen()  function returns the number of bytes in the
       string pointed to by s.*/