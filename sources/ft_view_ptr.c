/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:10 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/12 19:55:03 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_ptr(char *ptr, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (ft_strncmp(ptr, "(nil)", 5) != 0)
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
	if (!nbr)
		ptr = ft_substr("(nil)", 0, 5);
	else
	{
		ptr = ft_nbr_base(nbr, 16);
		ptr = ft_str_tolower(ptr);
	}
	len = ft_strlen(ptr);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_output_ptr(ptr, flags, len);
	if (nbr)
		count += ft_view_width(flags.width, len + 2, 0);
	else
		count += ft_view_width(flags.width, len, 0);
	if (flags.minus == 0)
		count += ft_output_ptr(ptr, flags, len);
	free(ptr);
	return (count);
}
