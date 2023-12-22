/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:51:07 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/21 14:18:11 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_arrays(void **arr1, void **arr2, void **arr3)
{
	int	flag;

	flag = 0;
	if (arr1)
	{
		flag++;
		free(*arr1);
	}
	if (arr2)
	{
		flag++;
		free(*arr2);
	}
	if (arr3)
	{
		flag++;
		free(*arr3);
	}
	return (flag);
}
