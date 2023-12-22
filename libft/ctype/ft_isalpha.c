/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:47 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:34:25 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*DESCRIPTION
       These functions check whether c, which must have the value
       of an unsigned char or EOF, falls into a certain character
       class according to the specified  locale.
	   isalpha()
              checks for an alphabetic character; in the standard
              "C"  locale, it is equivalent to (isupper(c) || is‐
              lower(c)).  In some locales,  there  may  be  addi‐
              tional  characters for which isalpha() is true—let‐
              ters which are neither uppercase nor lowercase.


RETURN VALUE
       The values returned are nonzero if the character  c  falls
       into the tested class, and zero if not.*/