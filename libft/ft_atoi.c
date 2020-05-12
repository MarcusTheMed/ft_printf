/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:52:38 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/07 13:44:04 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts start portion of a string to type int.
*/

int	ft_atoi(const char *nptr)
{
	unsigned long long	res;
	int					sign;
	size_t				count;

	res = 0;
	sign = 1;
	count = 0;
	while (*nptr == '\n' || *nptr == ' ' || *nptr == '\t' ||
			*nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
		count++;
	}
	if (res > 9223372036854775807 || count > 19)
		return ((sign == -1) ? 0 : -1);
	return ((int)res * sign);
}
