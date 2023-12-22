/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:08:08 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/19 12:34:47 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*DESCRIPTION
      The  bzero()  function  erases the data in the n bytes of the memory
      starting at the location pointed to by s, by  writing  zeros  (bytes
      containing '\0') to that area.

  RETURN VALUE
      None.*/