/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:05:48 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/12 19:05:49 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int len)
{
	int			count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar(str[count++]);
	return (count);
}
