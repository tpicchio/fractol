/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:00 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:35:28 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i > 0 && i == n)
		i--;
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

/*DESCRIPTION
       The  strncmp() function compares the two strings
       s1 and s2.  The locale is not  taken  into  ac‐
       count  (for a locale-aware comparison, see str‐
       coll(3)).  It returns  an  integer  less  than,
       equal  to, or greater than zero if s1 is found,
       respectively, to be less than, to match, or  be
       greater than s2.

       The  strncmp()  function  is similar, except it
       compares only the first (at most) n bytes of s1
       and s2.

RETURN VALUE
       The  strcmp() and strncmp() functions return an
       integer less than, equal to,  or  greater  than
       zero  if  s1  (or the first n bytes thereof) is
       found, respectively, to be less than, to match,
       or be greater than s2.*/