/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 13:53:27 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/13 13:56:07 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_view_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putchar('%');
	count += ft_view_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putchar('%');
	return (count);
}
