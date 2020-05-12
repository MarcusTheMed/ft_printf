/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:21 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/12 19:53:44 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_view(int c, t_flags flags, va_list av)
{
	int			count;

	count = 0;
	if (c == 'c')
		count += ft_view_char(va_arg(av, int), flags);
	else if (c == 's')
		count += ft_view_str(va_arg(av, char *), flags);
	else if (c == 'p')
		count += ft_view_ptr(va_arg(av, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count += ft_view_int(va_arg(av, int), flags);
	else if (c == 'u')
		count += ft_view_uint((unsigned int)va_arg(av, unsigned int), flags);
	else if (c == 'x')
		count += ft_view_hex(va_arg(av, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_view_hex(va_arg(av, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_view_percent();
	return (count);
}
