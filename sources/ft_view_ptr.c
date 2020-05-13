/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:10 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/13 17:35:31 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_ptr(char *ptr, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	count += ft_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_view_width(flags.dot, len, 1);
		count += ft_putstr(ptr, flags.dot);
	}
	else
		count += ft_putstr(ptr, len);
	return (count);
}

int			ft_view_ptr(unsigned long long nbr, t_flags flags)
{
	size_t	len;
	char	*ptr;
	int		count;

	count = 0;
	if (nbr == 0 && flags.dot == 0)
	{
		count += ft_putstr("0x", 2);
		return (count += ft_view_width(flags.width, 0, 1));
	}
	ptr = ft_str_tolower(ft_nbr_base(nbr, 16));
	len = ft_strlen(ptr);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_output_ptr(ptr, flags, len);
	count += ft_view_width(flags.width, len + 2, 0);
	if (flags.minus == 0)
		count += ft_output_ptr(ptr, flags, len);
	free(ptr);
	return (count);
}
