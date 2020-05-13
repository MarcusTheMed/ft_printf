/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:59:23 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/13 20:11:24 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_uns_itoa_base(unsigned long long nbr, int base)
{
	unsigned long long	nbr_tmp;
	char				*str;
	size_t				len;

	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr_tmp != 0)
	{
		nbr_tmp /= base;
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % base) + (nbr % base > 9 ? 55 : 48);
		nbr /= base;
		len--;
	}
	return (str);
}
