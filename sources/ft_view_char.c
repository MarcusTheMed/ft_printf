/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:05:56 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/12 19:53:04 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_view_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_view_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
