/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:47:53 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/07 14:03:19 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a pointer to the allocated memory.
** Allocates enough memory for an array of 'nmemb' objects each sized
** bytes 'size'.
** The allocated memory is filled with bytes of zero value.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;

	if (!(new = (void *)malloc(size * nmemb)))
		return (NULL);
	ft_bzero(new, size * nmemb);
	return (new);
}
