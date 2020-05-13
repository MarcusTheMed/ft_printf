/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:58:08 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/13 14:58:45 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int len)
{
	int	count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar(str[count++]);
	return (count);
}
